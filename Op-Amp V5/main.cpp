//
// Created by harry on 20/11/2024.
// Example implementation code for op_amp.h libarary
//

#include <iostream>
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

    const float* output_pointer = Amp.sim(0, 2, 0.1, 100, 0, 0); //pointer to the first value in the output array.
    float output_array[512]; //initialises an array of size 512 in which to store the output values.
    //for loop to iterate through the 512 address of the output array stored within op_amp::sim() and parse the values at each address to output_array[].
    for(int i = 0; i < 512; i ++) {
        output_array[i] = *(output_pointer + i);
        //prints the address and corresponding value.
        cout << output_pointer + i << ", ";
        cout << output_array[i] << endl;
    }
    return 0;
}
