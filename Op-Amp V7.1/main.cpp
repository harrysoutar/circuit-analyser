//
// Created by harry on 20/11/2024.
// Example implementation code for op_amp.h library
//

#include <iostream>
#include <fstream>
#include <vector>
#include "op_amp.h"

using namespace std;

op_amp Inverting(0, 0, 0, 100000, 1000);
op_amp Amp(100, 0, 0, 0, 0);
op_amp nonInverting(0, 5000, 1000, 0, 0);

int main() {
    Inverting.set_type("inverting");
    nonInverting.set_type("non-inverting");
    const string type = Amp.get_type();
    const float inverting_gain = Inverting.get_gain();
    const float nonInverting_gain = nonInverting.get_gain();

    vector<float> resistors = Amp.get_resistors(true,true); //returns the address of R1.
    for(const float resistor : resistors) {
        cout << resistor << ", ";
    }

    cout << endl;
    cout << "Amp is: " << type << endl;
    cout << "The inverting gain is: " << inverting_gain << endl;
    cout << "The non-inverting gain is: " << nonInverting_gain << endl;

    Amp.sim(0, 0.1, 100, 0, 0, true); //vector of 512 values.
    return 0;
}