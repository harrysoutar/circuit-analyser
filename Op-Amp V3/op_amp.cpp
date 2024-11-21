//
// Created by Harry Soutar on 20/11/2024.
//

#include <iostream>
#include "op_amp.h"


using namespace std;

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
        _gain = _r1/_r2;
    }else {
        return 0;
    }
    return _gain;
}

float op_amp::get_potential_divider() const {
    const float pot = _r1/(_r1+_r2);
    return pot;
}

float op_amp::get_Rf() const {
    return _rf;
}

