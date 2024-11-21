/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include "stardelta.h"

int main()
{
    bool type_of_conversion;
    std::cout << "Enter 0 for star to delta conversion or 1 For delta to star conversion" << "\n" ;
    std::cin >> type_of_conversion;
    
    if (type_of_conversion == 0){
        Star_Delta stardelta;
        std::cout << "You have chosen star to delta conversion." << "\n" << "Please enter r1: ";
        float r1;
        float r2;
        float r3;
        std::cin >> r1;
        std::cout <<"\n" << "Please enter r2: ";
        std::cin >> r2;
        std::cout <<"\n" << "Please enter r3: ";
        std::cin >> r3;
        
        stardelta.set_r1(r1);
        stardelta.set_r2(r2);
        stardelta.set_r3(r3);
        
        stardelta.get_ry();
        
        float R1R2 = stardelta.get_R1R2();
        float R1R3 = stardelta.get_R1R3();
        float R2R3 = stardelta.get_R2R3();
        
        std::cout << "R1R2 = " << R1R2 << "\n";
        std::cout << "R1R3 = " << R1R3 << "\n";
        std::cout << "R2R3 = " << R2R3 << "\n";
        
    }
    
    else{
        std::cout << "0";
    }

    return 0;
}