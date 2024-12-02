//
// Created by Harry Soutar on 20/11/2024.
//

#include <iostream>
#include "op_amp.h"
#include <cmath>
#include <vector>

using namespace std;
#define PI 3.14159265

op_amp::op_amp(const float gain, const float R1, const float R2, const float Rf, const float Rin):
_gain{gain},
_r1{R1},
_r2{R2},
_rf{Rf},
_rin{Rin}
{}

void op_amp::set_gain(const float gain) {
    _gain = gain;
}

void op_amp::set_type(const string &type) {
    _type = type;
}

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

string op_amp::get_type() {
    if(_gain >= 1) {
        _type = "non-inverting";
    }
    if(_gain <= -1) {
        _type = "inverting";
    }
    return _type;
}

float* op_amp::get_resistors(const bool feedback, const bool resistor_1) {
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
    float resistors[4] = {_r1, _r2, _rf, _rin};
    float *R_pointer = &resistors[0]; //address of R1 will be the returned value, the address of R2 will then be R_pointer + 1, Rf will be R_pointer + 2 and Rin will be +3.
    return R_pointer;
}

vector<float> op_amp::sim(const int start, const float amplitude, const float frequency, const float phase, const float DC_offset) const {
    vector<float> output_vector;
    const float data_gap = 1/(512*frequency); //distance between each data point (x-axis) (derived from (end - start)/512 = period / 512 = 1/(frequency*512)
    int k = 0;
    cout << "inter-function values: " << endl;
    for(int i = start; i < start + 512; i++) {
        const float time = static_cast<float>(i) * data_gap;
        output_vector.push_back(_gain*amplitude*sin((static_cast<float>(2*PI)*frequency*time)+phase)+DC_offset);
        k++;
    }
    return output_vector;
}


