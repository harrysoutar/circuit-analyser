#include <iostream>
#include <regex>
#include "HPLP.h"
#include "stardelta.h"
#include "op_amp.h"

void main_menu();
int get_user_input();
void select_menu_item(int input);
void print_main_menu();
void go_back_to_main();
bool is_integer(std::string num);
void menu_item_1();
void menu_item_2();
void menu_item_3();
void op_amp_menu();
void star_delta_menu();
void filter_menu();

int main(int argc, char const *argv[]) {
  main_menu();
  return 0;
}

void main_menu() {
  print_main_menu();
  int input = get_user_input();
  select_menu_item(input);
}

int get_user_input() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 5;

  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {  // if it is an int, check whether in range
      input = std::stoi(input_string);  // convert to int
      if (input >= 1 && input <= menu_items) {
        valid_input = true;
      } else {
        std::cout << "Invalid menu item!\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  return input;
}

void select_menu_item(int input) {
  switch (input) {
    case 1:
      menu_item_1();
      break;
    case 2:
      menu_item_2();
      break;
    case 3:
      menu_item_3();
      break;
    default:
      exit(1);
      break;
  }
}

void print_main_menu() {
  std::cout << "\n----------------- Main menu -----------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Op-Amp Calculator & Simulator\t\t|\n";
  std::cout << "|\t2. Filter Calculator\t\t\t\t\t|\n";
  std::cout << "|\t3. Star-Delta Converter\t\t\t\t\t|\n";
  std::cout << "|\t4. Exit\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "---------------------------------------------\n";
}

void go_back_to_main() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to go back to main menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  main_menu();
}

// https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit
bool is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

void op_amp_menu() {
  int input_1;
  float gain = 0.0;
  std::string resistor;
  op_amp amp(gain,0,0,0,0);
  amp.get_type(); //works out the type based on private variable _gain.

  std::cout << "\n------------ Op-Amp -------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t|";
  std::cout << "\n|\t1. Op-Amp Calculator\t\t|\n";
  std::cout << "|\t2. Op-Amp Simulator\t\t\t|";
  std::cout << "\n|\t\t\t\t\t\t\t\t|\n";
  std::cout << "---------------------------------" << std::endl;
  std::cout << "Select item: ";
  std::cin >> input_1;
  if(input_1 == 1) {
    int input_2;
    std::cout << "\n---------- Calculator ----------\n";
    std::cout << "|\t\t\t\t\t\t\t\t|";
    std::cout << "\n|\t1.Resistor Calculation\t\t|\n";
    std::cout << "|\t2.Gain Calculation\t\t\t|";
    std::cout << "\n|\t\t\t\t\t\t\t\t|\n";
    std::cout << "---------------------------------\n";
    std::cout << "Select item: ";
    std::cin >> input_2;
    if(input_2 == 1) {
      std::cout << "Please input gain (include sign for inverting or non-inverting): ";
      std::cin >> gain;
      if(gain < 0) {
        std::cout << "Would you like to calculate Rf or Rin? ";
        cin >> resistor;
        bool Rf = false;
        if(resistor == "Rf") {
          Rf = true;
        }
        else if(resistor == "Rin") {
          Rf = false;
        }
        else {
          std::cout << "invalid input";
          go_back_to_main();
        }
        amp.get_resistors(Rf, false);
      }
      if(gain > 0) {
        std::cout << "Would you like to calculate R1 or R2? ";
        cin >> resistor;
        bool R1 = false;
        if(resistor == "R1") {
          R1 = true;
        }
        else if(resistor == "R2") {
          R1 = false;
        }
        else {
          std::cout << "invalid input";
          go_back_to_main();
        }
        vector<float> const resistors = amp.get_resistors(false, R1);
        for(int i = 0; i < 4; i++) {
          std::cout << resistors[i] << ", ";
        }
      }
    }
  }
  }



void menu_item_1() {
  op_amp_menu();
}

void star_delta_menu() {
  //label1 is for the goto function in the else statement
    label1:
    //for the menu points
    int type_of_conversion;
    //ASCII drawing of the connection diagram (Im open for improvements)
    std::cout << " _______________________ " << "\n"
              << "| circuit diagram:      |" << "\n"
              << "|                       |" << "\n"
              << "|  a      b  a-R1R2-b   |" << "\n"
              << "|   (    /    (    /    |" << "\n"
              << "|   r1  r 2  R1R23 R2R3 |" << "\n"
              << "|     (/        (/      |" << "\n"
              << "|      |        c       |" << "\n"
              << "|      r3               |" << "\n"
              << "|      |                |" << "\n"
              << "|      c                |" << "\n"
              << "|_______________________|" << "\n" << "\n";
    std::cout << " ________________________________ " << "\n"
              << "| Enter:                         |" << "\n"
              << "|  0 for star to delta conversion|" << "\n"
              << "|  1 For delta to star conversion|" << "\n"
              << "|  2 to exit                     |" << "\n"
              << "|________________________________|" << "\n";
    std::cin >> type_of_conversion;
    //star delta conversion
    if (type_of_conversion == 0){
        Star_Delta stardelta;
        float r1, r2, r3;
        std::cout << "You have chosen star to delta conversion." << "\n";
    //jump for wrong r1 value
        labelr1:
        std::cout << "Please enter r1: ";
        std::cin >> r1;
    //handling cases with incorrect resistor values
        if(r1 <= 0){
            std::cout << "Incorrect value" << "\n";
            goto labelr1;
            std::cout << "\n";
        }
    //jump for wrong r2 value
        labelr2:
        std::cout <<"\n" << "Please enter r2: ";
        std::cin >> r2;
    //handling cases with incorrect resistor values
        if(r2 <= 0){
            std::cout << "Incorrect value" << "\n";
            goto labelr2;
            std::cout << "\n";
        }
    //jump for wrong r3 value
        labelr3:
        std::cout <<"\n" << "Please enter r3: ";
        std::cin >> r3;
    //handling cases with incorrect resistor values
        if(r3 <= 0){
            std::cout << "Incorrect value" << "\n";
            goto labelr3;
            std::cout << "\n";
        }

        stardelta.set_r1(r1);
        stardelta.set_r2(r2);
        stardelta.set_r3(r3);

        stardelta.get_Rvalues();

        goto label1;
    }
    // delta star conversion
    else if(type_of_conversion == 1){
        Delta_Star deltastar;
        float R1R2, R1R3, R2R3;
        std::cout << "You have chosen delta to star conversion." << "\n";
    //jump for wrong R1R2 value
        labelR1R2:
        std::cout<< "Please enter R1R2: ";
        std::cin >> R1R2;
    //handling cases with incorrect resistor values
        if(R1R2 <= 0){
            goto labelR1R2;
            std::cout << "\n";
        }
    //jump for wrong R1R3 value
        labelR1R3:
        std::cout <<"\n" << "Please enter R1R2: ";
        std::cin >> R1R3;
    //handling cases with incorrect resistor values
        if(R1R3 <= 0){
            goto labelR1R3;
            std::cout << "\n";
        }
    //jump for wrong R2R3 value
        labelR2R3:
        std::cout <<"\n" << "Please enter R2R3: ";
        std::cin >> R2R3;
    //handling cases with incorrect resistor values
        if(R2R3 <= 0){
            goto labelR2R3;
            std::cout << "\n";
        }

        deltastar.set_R1R2(R1R2);
        deltastar.set_R1R3(R1R3);
        deltastar.set_R2R3(R2R3);

        deltastar.get_rvalues();

        goto label1;
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
  std::cout << endl;
}

  void filter_menu() {
  Filter Filter;
  std::string filter_type;
  double resistor, capacitor;

  std::cout << "Welcome to the Filter Calculator!" << std::endl;

  // Get filter type
  do {
    std::cout << "Enter the filter type (high-pass or low-pass): ";
    std::cin >> filter_type;
    if (!Filter::is_valid_filter_type(filter_type)) {
      std::cout << "Invalid filter type! Please enter 'HP' or 'LP'." << std::endl;
    } else {
      Filter.set_filter(filter_type);
    }
  } while (!Filter::is_valid_filter_type(filter_type));

  // Get and validate resistor value
  std::cout << "Enter the resistor value (in ohms): ";
  std::cin >> resistor;
  Filter.set_resistor(resistor);

  // Get and validate capacitor value
  std::cout << "Enter the capacitor value (in farads): ";
  std::cin >> capacitor;
  Filter.set_capacitor(capacitor);

  // Display the result
  Filter.output_result();

    main_menu();
    }

void menu_item_2() {
  filter_menu();
}
void menu_item_3() {
  star_delta_menu();
}