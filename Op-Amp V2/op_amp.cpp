//
// Created by Harry Soutar on 20/11/2024.
//

#include "op_amp.h"
#include <iostream>

using namespace std;

void op_amp::set_gain(int gain) {
    gain = _gain;
}

string op_amp::set_type(string type) {
    _type = type;
}

void op_amp::set_Rf(const double Rf) {
    _Rf = Rf;
}

void op_amp::set_Rin(const double Rin) {
    _Rin = Rin;
}

void op_amp::set_R1(const double R1) {
    _R1 = R1;
}

void op_amp::set_R2(const double R2) {
    _R2 = R2;
}

int op_amp::get_gain() {
    if(_type == "inverting") {
        cout << "Invert gain" << endl;
        _gain = -(_Rf/_Rin);
    }
    else if(_type == "non-inverting") {
        cout << "Non-invert gain" << endl;
        _gain = _R1/_R2;
    }else {
        cout << "Invalid type or type not set" << endl;
        return 0;
    }
    return _gain;
}