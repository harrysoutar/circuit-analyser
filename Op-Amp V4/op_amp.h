//
// Created by Harry Soutar on 20/11/2024.
//

#ifndef OP_AMP_H
#define OP_AMP_H

#include <iostream>
#include <string>

using namespace std;

class op_amp {
public:
    op_amp(float gain, float R1, float R2, float Rf, float Rin);
    void set_type(const string &type);
    string get_type();
    float get_gain(); //returns gain dependant on type and resistance.
    void set_gain(float gain);


    //inverting topology function
    void set_Rf(float Rf); // sets feedback resistor value


    //non-inverting topology functions
    void set_R1(float R1); //sets R1
    void set_R2(float R2); //sets R2
    void set_Rin(float Rin);
    float* get_resistors(bool feedback, bool resistor_1); //returns the potential divider proportion to choose R1 and R2.

    //simulation functions
    float sim(float input_val) const; //simulates the Op-Amp output i.e., outputs based on the transfer function.

private:
    float _gain;
    float _r1;
    float _r2;
    float _rf;
    float _rin;
    string _type;

};



#endif //OP_AMP_H
