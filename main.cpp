#include <iostream>
#include "stardelta.h"

int main()
{
    //label1 is for the goto function in the else statement
    label1:
    //for the menu points
    int type_of_conversion;
    //ASCII drawing of the connection diagram (Im open for improvements)
    std::cout << "a      b  a-R1R2-b" << "\n"
              << " (    /    (    / " << "\n"
              << " r1  r2  R1R23 R2R3" << "\n"
              << "   (/        (/    " << "\n"
              << "    l        c" <<"\n"
              << "    r3" << "\n"
              << "    l" << "\n" 
              << "    c" << "\n";
    std::cout << "Enter 0 for star to delta conversion 1 For delta to star conversion, or 2 to exit" << "\n" ;
    std::cin >> type_of_conversion;
    //star delta conversion
    if (type_of_conversion == 0){
        Star_Delta stardelta;
        float r1, r2, r3;
        std::cout << "You have chosen star to delta conversion." << "\n" << "Please enter r1: ";
        std::cin >> r1;
        std::cout <<"\n" << "Please enter r2: ";
        std::cin >> r2;
        std::cout <<"\n" << "Please enter r3: ";
        std::cin >> r3;
        
        stardelta.set_r1(r1);
        stardelta.set_r2(r2);
        stardelta.set_r3(r3);
        
        stardelta.get_Rvalues();
    }
    // delta star conversion
    else if(type_of_conversion == 1){
        Delta_Star deltastar;
        float R1R2, R1R3, R2R3;
        std::cout << "You have chosen delta to star conversion." << "\n" << "Please enter R1R2: ";
        std::cin >> R1R2;
        std::cout <<"\n" << "Please enter R1R2: ";
        std::cin >> R1R3;
        std::cout <<"\n" << "Please enter R2R3: ";
        std::cin >> R2R3;
        
        deltastar.set_R1R2(R1R2);
        deltastar.set_R1R3(R1R3);
        deltastar.set_R2R3(R2R3);
        
        deltastar.get_rvalues();
    }
    //option to exit the code
    else if(type_of_conversion == 2){
        goto label2;
    }
    // option to return to star delta menu point
    else {
        std::cout << "You pressed the wrong number" << "\n";
        goto label1;
    }
    // goto function to exit the code
    label2:
    return 0;
}