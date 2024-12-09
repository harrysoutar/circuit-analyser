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
//This is not a necessary function but added for redundancy and additional user functionality.
void op_amp::set_gain(const float gain) {
    _gain = gain;
}
//mutator for setting the type of the amplifier. Depending on the use case the software can deduce the type based on
//attributes of the object however in some cases it may need to be modified post initialisation.
void op_amp::set_type(const string &type) {
    _type = type;
}

//The following four functions are mutators for setting resistor values. Alike set_gain() these are redundancies.
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

//returns a vector of size four with the resistor values calculated based on attributes of the object
//such as gain, and a single resistor value (see documentation for more)
vector <float> op_amp::get_resistors(const bool feedback, const bool resistor_1) {
    if(_type == "inverting") {
        if(feedback == true) {
            if(_rin == 0) {
                cout << "Rin is required to find Rf, please input a value for Rin: ";
                cin >> _rin;
            }
            _rf = -_gain*_rin;
        }
        if(feedback == false) {
            if(_rf == 0) {
                cout << "Rf is required to find Rin, please input a value for Rf: ";
                cin >> _rf;
            }
            _rin = -_gain / _rf;
        }
    }
    if(_type == "non-inverting") {
        if(resistor_1 == true) {
            if(_r2 == 0) {
                cout << "R2 is required to find R1, please input a value for R2: ";
                cin >> _r2;
            }
            _r1 = _r2*(_gain - 1);
        }
        if(resistor_1 == false) {
            if(_r1 == 0) {
                cout << "R1 is required to find R2, please input a value for R1: ";
                cin >> _r1;
            }
            _r2 = _r1/(_gain-1);
        }
    }
    vector<float> resistors = {_r1, _r2, _rf, _rin};
    return resistors;
}
//simulation function that outputs a vector of size 512 (9-bit resolution) of output values of the simulated op-amp
//circuit. The input arguments are attributes of a sinusoidal wave-form.
void op_amp::sim(const int start, const float amplitude, const float frequency, const float phase, const float DC_offset, const bool vertical) const {
    vector<float> data_vector;
    const float data_gap = 1/(512*frequency); //distance between each data point (x-axis) (derived from (end - start)/512 = period / 512 = 1/(frequency*512)
    int k = 0;
    cout << "inter-function values: " << endl;
    for(int i = start; i < start + 512; i++) {
        const float time = static_cast<float>(i) * data_gap;
        data_vector.push_back(_gain*amplitude*sin((static_cast<float>(2*PI)*frequency*time)+phase)+DC_offset);
        k++;
    }
    ofstream simulation("simulation.csv");
    for(int i = 0; i < 512; i++) {
        simulation << data_vector[i] << ',';
        const bool end_line = i == 16 || i == 32 || i == 48 || i == 64|| i == 80|| i == 96 || i == 112 || i == 128 ||
        i == 144 || i == 160 || i == 176 || i == 192 || i == 208 || i == 224 || i == 240 || i == 256 || i == 272 || i == 288 ||
        i == 304 || i == 320 || i == 336 || i == 352 || i == 368 || i == 384 || i == 400 || i == 416 || i == 432|| i == 448 ||
        i == 464 || i == 480 || i == 496;
        if(end_line == true && vertical == false) {
            simulation << endl;
        }
        if (vertical == true) {
            simulation << endl;
        }
    }
    simulation.close();
}


