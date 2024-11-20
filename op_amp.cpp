//
// Created by Harry Soutar on 20/11/2024.
//

#include "op_amp.h"
#include <iostream>

using namespace std;

op_amp::op_amp(int gain, string type, double Rf, double Rin, double R1, double R2) :
    _gain{gain},
    _type{type},
    _Rf{Rf},
    _Rin{Rin},
    _R1{R1},
    _R2{R2}
{}


void op_amp::set_gain(int gain) {
    gain = _gain;
}

int op_amp::get_gain() {
    _gain = -_Rf;
}

string op_amp::set_type(string type) {
    type = _type;
}

void op_amp::set_Rf(double Rf) {
    Rf = _Rf;
}

void op_amp::set_Rin(double Rin) {
    Rin = _Rin;
}

void op_amp::set_R1(double R1) {
    R1 = _R1;
}

void op_amp::set_R2(double R2) {
    R2 = _R2;
}