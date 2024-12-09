//
// Created by Harry Soutar on 20/11/2024.
//

#include <iostream>
#include "op_amp.h"
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;
#define PI 3.14159265

//Constructor to initialise the op_amp class with attributes gain, R1, R2, Rf, and Rin
op_amp::op_amp(const float gain, const float R1, const float R2, const float Rf, const float Rin):
_gain{gain},
_r1{R1},
_r2{R2},
_rf{Rf},
_rin{Rin}
{}

//mutator for accessing and altering the private variable _gain
void op_amp::set_gain(const float gain) {
    _gain = gain;
}
//mutator for setting the type of the amplifier. Depending on the use case the software can deduce the type based on
//attributes of the object however in some cases it may need to be modified post initialisation.
//pass by reference is being used here as strings cannot be passed by value into functions.
void op_amp::set_type(const string &type) {
    _type = type;
}

//The following four functions are mutators for setting resistor values.
void op_amp::set_Rf(const float Rf) {
    _rf = Rf;
}

void op_amp::set_Rin(const float Rin) {
    _rin = Rin;
}

void op_amp::set_R1(const float R1) {
    _r1 = R1;
}

void op_amp::set_R2(const float R2) {
    _r2 = R2;
}

//calculates the gain value based on the type and resistor values.
float op_amp::get_gain() {
    if(_type == "inverting") {
        _gain = -(_rf/_rin);
    }
    else if(_type == "non-inverting") {
        _gain = 1 + (_r1/_r2);
    }else {
        return 0;
    }
    return _gain;
}

//Finds the type of the amplifier dependent on whether gain is + or -
string op_amp::get_type() {
    if(_gain >= 1) {
        _type = "non-inverting";
    }
    if(_gain <= -1) {
        _type = "inverting";
    }
    return _type;
}

//prints out the values of required resistors based on gain and one of the resistor values.
//this resistor value is mostly arbitrary, but it should be chosen based on knowledge of op-amp characteristics
//and the specific use-case of the op-amp circuit.
void op_amp::get_resistors(const bool feedback, const bool resistor_1) {
    get_type();
    if(_type == "inverting") {
        if(feedback == true) {
            set_Rf(-_gain*_rin);
            std::cout << " Rf = " << _rf << std::endl;
        }
        if(feedback == false) {
            set_Rin(-_gain / _rf);
            std::cout << " Rin = " << _rin << std::endl;
        }
    }
    if(_type == "non-inverting") {
        if(resistor_1 == true) {
            set_R1(_r2*(_gain - 1));
            std::cout << " R1 = " << _r1 << std::endl;
        }
        if(resistor_1 == false) {
            set_R2(_r1/(_gain-1));
            std::cout << " R2 = " << _r2 << std::endl;
        }
    }
}

//simulation function that outputs a vector of size 512 (9-bit resolution) of output values of the simulated op-amp
//circuit. The input arguments are attributes of a sinusoidal wave-form.
void op_amp::sim(const int start, const float amplitude, const float frequency, const float phase, const float DC_offset, const bool vertical) const {
    //vector to hold the data output of the simulation.
    vector<float> data_vector;
    //distance between each data point (x-axis) (derived from (end - start)/512 = period / 512 = 1/(frequency*512)
    const float data_gap = 1/(512*frequency);
    //iterates through all 512 time steps and generates a 'time' value based on the frequency and step number.
    for(int i = start; i < start + 512; i++) {
        const float time = static_cast<float>(i) * data_gap;
        //adds the value to the data vector
        data_vector.push_back(_gain*amplitude*sin(static_cast<float>(2*PI)*frequency*(time+phase))+DC_offset);
    }
    //generates a new csv file in which to store the output data
    ofstream simulation("simulation.csv");
    //iterates through the generated vector of data and writes each data point to the simulation csv file.
    for(int i = 0; i < 512; i++) {
        simulation << data_vector[i] << ',';
        //end line feature ends line after every 16 data entries.
        const bool end_line = i == 16 || i == 32 || i == 48 || i == 64|| i == 80|| i == 96 || i == 112 || i == 128 ||
        i == 144 || i == 160 || i == 176 || i == 192 || i == 208 || i == 224 || i == 240 || i == 256 || i == 272 || i == 288 ||
        i == 304 || i == 320 || i == 336 || i == 352 || i == 368 || i == 384 || i == 400 || i == 416 || i == 432|| i == 448 ||
        i == 464 || i == 480 || i == 496;
        //only uses end line if user wishes to do so. some may wish to have a column of data for an excel sheet.
        if(end_line == true && vertical == false) {
            simulation << endl;
        }
        if (vertical == true) {
            simulation << endl;
        }
    }
    //closes the simulation file to avoid undefined behavior and loss of data.
    simulation.close();
}


