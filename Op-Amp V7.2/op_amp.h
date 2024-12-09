//
// Created by Harry Soutar on 20/11/2024.
//

#ifndef OP_AMP_H
#define OP_AMP_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class op_amp {
public:
    op_amp(float gain, float R1, float R2, float Rf, float Rin); //constructor declaration, initialises the class with public variables.

    //functions for any type of Op-Amp circuit
    void set_type(const string &type); //sets the type of the Op-Amp if not provided in object initialisation, either 'non-inverting' or 'inverting'
    string get_type(); //returns the type of the circuit.
    float get_gain(); //returns gain dependant on type and resistance.
    void set_gain(float gain); //sets the gain if not set in object initialisation.
    //note most of the above functions are redundancies that in theory aren't required but make the library more user-friendly and


    //inverting topology function
    void set_Rf(float Rf); // sets feedback resistor value


    //non-inverting topology functions
    void set_R1(float R1); //sets the value of R1
    void set_R2(float R2); //sets the value of R2
    void set_Rin(float Rin); //sets the value of Rin
    void get_resistors(bool feedback, bool resistor_1); //returns a pointer the first value in an array of all four resistor values. This can then be used to return the values of the subsequent resistors.

    //simulation functions
    void sim(int start, float amplitude, float frequency, float phase, float DC_offset, bool vertical) const; //simulates the Op-Amp output i.e., outputs based on the transfer function.

private:
    //private variables for gain, resistor values, and the type.
    float _gain;
    float _r1;
    float _r2;
    float _rf;
    float _rin;
    string _type;

};

#endif //OP_AMP_H
