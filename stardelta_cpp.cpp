#include "stardelta.h"

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

//calculating ry
float Star_Delta::get_ry(){
    _ry = 1 / ((1 / _r1) + (1 / _r2) + (1 / _r3));
    return _ry;
}

//calculating R1R2
float Star_Delta::get_R1R2(){
    _R1R2 = (_r1 * _r2) / _ry;
    return _R1R2;
}

//calculating R1R3
float Star_Delta::get_R1R3(){
    _R1R3 = (_r1 * _r3) / _ry;
    return _R1R3;
}

//calculating R2R3
float Star_Delta::get_R2R3(){
    _R2R3 = (_r2 * _r3) / _ry;
    return _R2R3;
}

//caclulating RX
float Delta_Star::get_RX(){
    _RX = _R1R2 + _R1R3 + _R2R3;
    return _RX;
}

//calculating r1 
float Delta_Star::get_r1(){
    _r1 = (_R1R2 * _R1R3) / _RX;
    return _r1;
}

//calculating r2
float Delta_Star::get_r2(){
    _r2 = (_R1R2 * _R2R3) / _RX;
    return _r2;
}

//calculating r3
float Delta_Star::get_r3(){
    _r3 = (_R1R3 * _R2R3) / _RX;
    return _r3;
}

