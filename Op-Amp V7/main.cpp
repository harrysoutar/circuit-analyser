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

    const float* add_R1 = Amp.get_resistors(true,true); //returns the address of R1.
    const float resistors[4] = {*add_R1, *(add_R1+1), *(add_R1+2), *(add_R1+3)};
    for(const float resistor : resistors) {
        cout << resistor << ", ";
    }

    cout << endl;
    cout << "Amp is: " << type << endl;
    cout << "The inverting gain is: " << inverting_gain << endl;
    cout << "The non-inverting gain is: " << nonInverting_gain << endl;

    ofstream simulation("simulation.csv");
    const vector<float> output = Amp.sim(0, 0.1, 100, 0, 0); //vector of 512 values.
    for(int i = 0; i < 512; i++) {
        cout << output[i] << endl;
        simulation << output[i] << endl;
    }
    simulation.close();
    return 0;
}