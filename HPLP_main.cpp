#include <iostream>
#include "HPLP.h" // Include the header file that defines the Filter class

int main() {
    Filter Filter; // Create an instance of the Filter class
    std::string filter_type; // Variable to store the filter type (high-pass or low-pass)
    double resistor, capacitor; // Variables to store resistor and capacitor values

    std::cout << "Welcome to the Filter Calculator!" << std::endl;

    // Get the filter type from the user
    do {
        std::cout << "Enter the filter type (high-pass or low-pass): ";
        std::cin >> filter_type; // Read the filter type from the user

        // Validate the filter type
        if (!Filter::is_valid_filter_type(filter_type)) {
            // If invalid, prompt the user to enter again
            std::cout << "Invalid filter type! Please enter 'high-pass' or 'low-pass'." << std::endl;
        } else {
            // If valid, set the filter type in the Filter object
            Filter.set_filter(filter_type);
        }
    } while (!Filter::is_valid_filter_type(filter_type)); // Repeat until a valid filter type is provided

    // Get the resistor value from the user
    std::cout << "Enter the resistor value (in ohms): ";
    std::cin >> resistor; // Read the resistor value
    Filter.set_resistor(resistor); // Set the resistor value in the Filter object

    // Get the capacitor value from the user
    std::cout << "Enter the capacitor value (in farads): ";
    std::cin >> capacitor; // Read the capacitor value
    Filter.set_capacitor(capacitor); // Set the capacitor value in the Filter object

    // Display the calculated cutoff frequency to the user
    Filter.output_result();

    return 0; // End the program
}
