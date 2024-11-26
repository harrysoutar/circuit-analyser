//
// Created by harry on 20/11/2024.
// Example implementation code for op_amp.h libarary
//

#include <iostream>
#include "op_amp.h"
#include <cmath>

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


    const float test = 10*sin(static_cast<float>(2*3.141592654*0.25)); //make 'get_input function to make a sin wave from input variables (frequency & amplitude)'
    cout << test;
    return 0;
}
