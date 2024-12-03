#include <iostream>
#include "HPLP.h"
#include <limits>

int main() {
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

    return 0;
}
