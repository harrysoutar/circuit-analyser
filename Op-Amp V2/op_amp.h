//
// Created by Harry Soutar on 20/11/2024.
//
#include <string>

using namespace std;

#ifndef OP_AMP_H
#define OP_AMP_H



class op_amp {
public:
    string set_type(string type);
    int get_gain(); //returns gain dependant on type and resistance.
    void set_gain(int gain);


    //inverting topology function
    void set_Rf(double Rf); // sets feedback resistor value
    void set_Rin(double Rin); //sets input resistor value
    double get_Rf(); //returns Rf based on inverting gain

    //non-inverting topology functions
    void set_R1(double R1); //sets R1
    void set_R2(double R2); //sets R2
    double get_potential_divider(); //returns the potential divider proportion to choose R1 and R2.


private:
    double _R1;
    double _R2;
    double _Rf;
    double _Rin;
    int _gain;
    string _type;

};



#endif //OP_AMP_H
