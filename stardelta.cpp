#include "stardelta.h"
#include <iostream>

//constructors
Star_Delta::Star_Delta() {}
Delta_Star::Delta_Star() {}

//setting the resistor values for the star to delta conversion
void Star_Delta::set_r1(float r1){_r1 = r1;}
void Star_Delta::set_r2(float r2){_r2 = r2;}
void Star_Delta::set_r3(float r3){_r3 = r3;}

//setting the resistor values for the delta to star conversion
void Delta_Star::set_R1R2(float R1R2){_R1R2 = R1R2;}
void Delta_Star::set_R1R3(float R1R3){_R1R3 = R1R3;}
void Delta_Star::set_R2R3(float R2R3){_R2R3 = R2R3;}

//calculating and printing R1R2, R1R3 and R2R3 values
void Star_Delta::get_Rvalues(){
    _ry = 1 / ((1 / _r1) + (1 / _r2) + (1 / _r3));
    _R1R2 = (_r1 * _r2) / _ry;
    _R1R3 = (_r1 * _r3) / _ry;
    _R2R3 = (_r2 * _r3) / _ry;
    std::cout << "R1R2 = " << _R1R2 << "\n";
    std::cout << "R1R3 = " << _R1R3 << "\n";
    std::cout << "R2R3 = " << _R2R3 << "\n";
    
}

//calculating and printing r1, r2 and r3 values
void Delta_Star::get_rvalues(){
    _RX = _R1R2 + _R1R3 + _R2R3;
    _r1 = (_R1R2 * _R1R3) / _RX;
    _r2 = (_R1R2 * _R2R3) / _RX;
    _r3 = (_R1R3 * _R2R3) / _RX;
    std::cout << "r1 = " << _r1 << "\n";
    std::cout << "r2 = " << _r2 << "\n";
    std::cout << "r3 = " << _r3 << "\n";
}

