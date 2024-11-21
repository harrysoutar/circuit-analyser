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
    const float inverting_gain = Inverting.get_gain();
    const float nonInverting_gain = nonInverting.get_gain();
    cout << "The inverting gain is: " << inverting_gain << endl;
    cout << "The non-inverting gain is: " << nonInverting_gain << endl;
    return 0;
}
