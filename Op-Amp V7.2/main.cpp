//
// Created by harry on 20/11/2024.
// Example implementation code for op_amp.h library
//

#include <iostream>
#include "op_amp.h"

int main() {
    int input_1;
    //initialises the op-amp object with the class op_amp.h
    op_amp amp(0,0,0,0,0);

    //sub-menu one
    std::cout << "\n------------ Op-Amp -------------\n";
    std::cout << "|\t\t\t\t|";
    std::cout << "\n|\t1. Op-Amp Calculator\t|\n";
    std::cout << "|\t2. Op-Amp Simulator\t|";
    std::cout << "\n|\t\t\t\t|\n";
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Select item: ";
    std::cin >> input_1;
    if(input_1 == 1) { //determines whether the user wishes to calculate or simulate
        int input_2; //sub-menu two for calculator functionality.
        std::cout << "\n---------- Calculator -----------\n";
        std::cout << "|\t\t\t\t|";
        std::cout << "\n|\t1.Resistor Calculation\t|\n";
        std::cout << "|\t2.Gain Calculation\t|";
        std::cout << "\n|\t\t\t\t|\n";
        std::cout << "---------------------------------\n";
        std::cout << "Select item: ";
        std::cin >> input_2;
        if(input_2 == 1) { //determines whether the user wishes to calculate gain or resistance values.
            float gain;
            std::string resistor;
            std::cout << "Please input gain (include sign for inverting or non-inverting): ";
            std::cin >> gain;
            amp.set_gain(gain);
            if(gain < 0) {
                std::cout << "Would you like to calculate Rf or Rin? ";
                cin >> resistor;
                bool feedback = false;
                if(resistor == "Rf") {
                    float Rin;
                    //feedback is a bool input into 'get_resistors' to tell it which resistor to calculate.
                    feedback = true;
                    //The resistor values will always be in ratio meaning one is needed to calculate the other.
                    //The value of the first one can be pretty arbitrary, although it should be based on op-amp
                    //characteristics. See documentation for more.
                    std::cout << "Rin is required to calculate Rf, please input a value for Rin: ";
                    std::cin >> Rin;
                    amp.set_Rin(Rin);
                    amp.get_resistors(feedback, false);
                }
                else if(resistor == "Rin") {
                    feedback = false;
                    float Rf;
                    std::cout << "Rf is required to calculate Rin, please input a values for Rf: ";
                    std::cin >> Rf;
                    amp.set_Rf(Rf);
                    amp.get_resistors(feedback, false);
                }
                else {
                    std::cout << "invalid input";
                    //go_back_to_main();
                }
            }
            if(gain > 0) {
                std::cout << "Would you like to calculate R1 or R2? ";
                cin >> resistor;
                //Resistor_1 is a bool input into 'get_resistors' to tell it which resistor to calculate.
                bool Resistor_1 = false;
                if(resistor == "R1") {
                    float R2;
                    Resistor_1 = true;
                    std::cout << "R2 is required to calculate R1, please input a value for R2: ";
                    std::cin >> R2;
                    //mutator function to set the value of R2 after receiving user input.
                    amp.set_R2(R2);
                    //calls get_resistors function after setting private variables.
                    amp.get_resistors(false, Resistor_1);
                }
                else if(resistor == "R2") {
                    Resistor_1 = false;
                    float R1;
                    std::cout << "R1 is required to calculate R2, please input a values for R1: ";
                    std::cin >> R1;
                    amp.set_R1(R1);
                    amp.get_resistors(false, Resistor_1);
                }
                else {
                    std::cout << "invalid input";
                    //go_back_to_main();
                }
            }
        }
        if(input_2 == 2) {
            std::string type;
            std::cout << "Please input the type, inverting or non-inverting: ";
            std::cin >> type;
            amp.set_type(type);
            if(type == "inverting") {
                float Rf;
                float Rin;
                std::cout << "Please input Rf: ";
                std::cin >> Rf;
                std::cout << "Please input Rin: ";
                std::cin >> Rin;
                amp.set_Rf(Rf);
                amp.set_Rin(Rin);
            }
            if(type == "non-inverting") {
                float R1;
                float R2;
                std::cout << "Please input R1: ";
                std::cin >> R1;
                std::cout << "Please input R2: ";
                std::cin >> R2;
                amp.set_R1(R1);
                amp.set_R2(R2);
            }
            std::cout << amp.get_gain();
        }
    }
    if(input_1 == 2) {
        float gain;
        float amplitude;
        int start;
        float frequency;
        float phase;
        float offset;
        std::string file_format;
        bool vertical;
        std::cout << "Please input gain: ";
        std::cin >> gain;
        amp.set_gain(gain);
        std::cout << "Please input the following characteristics of the input waveform: " << std::endl;
        std::cout << "Amplitude: ";
        std::cin >> amplitude;
        std::cout << "Start time (seconds): ";
        std::cin >> start;
        std::cout << "Frequency (Hz): ";
        std::cin >> frequency;
        std::cout << "Phase (seconds): ";
        std::cin >> phase;
        std::cout << "DC Offset (volts): ";
        std::cin >> offset;
        std::cout << "Would you like the output data in a vertical column format? Please input true or false ";
        std::cin >> file_format;

        if(file_format == "true") {
            vertical = true;
        }
        else {
            vertical = false;
        }
        amp.sim(start, amplitude, frequency, phase, offset, vertical);
    }
    return 0;
}