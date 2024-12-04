#ifndef STARDELTA_H
#define STARDELTA_H

//initialising variables for the star to delta conversion
class Star_Delta {
    public:
    Star_Delta();
//r1, r2, r3 are the resistors of the star resistor network
    void set_r1(float r1);
    void set_r2(float r2);
    void set_r3(float r3);
//R1R2, R2R3, R1R3 are the resistors of the Delta resistor network
//ry is a variable needed for calculating the conversion
//get_Rvalues calculates the R1R2, R1R3 and R2R3 values
    void get_Rvalues();

    private:
    float _r1;
    float _r2;
    float _r3;
    float _ry;
    float _R1R2;
    float _R1R3;
    float _R2R3;
};

//initialising variables for the delta to star conversion
class Delta_Star {
    
    public:
    Delta_Star();
    void set_R1R2(float R1R2);
    void set_R1R3(float R1R3);
    void set_R2R3(float R2R3);
//RX is needed for the delta to star conversion
//get_rvalues calculates the r1, r2 and r3 values
    void get_rvalues();
    
    private:
    float _r1;
    float _r2;
    float _r3;
    float _RX;
    float _R1R2;
    float _R1R3;
    float _R2R3;
};

#endif