#include <iostream>
#include <iomanip>
#include "HPLP.h"

// Constructor
Filter::Filter() : _filter_type("LP"), _resistor(0.0), _capacitor(0.0) {}

// Setter for filter type
// Allows setting the filter type as either "HP" (high-pass) or "LP" (low-pass).
void Filter::set_filter(const std::string& filter_type) {
    if (isValidFilterType(filter_type)) {
        _filter_type = filter_type;
    } else {
        // Error message if the filter type is invalid
        std::cerr << "Invalid filter type! Use 'HP' for high-pass or 'LP' for low-pass.\n";
    }
}

// Setter for resistor value
// Ensures that the resistor value is positive before setting it.
void Filter::set_resistor(double resistor) {
    if (resistor > 0.0) {
        _resistor = resistor;
    } else {
        // Error message if the resistor value is invalid
        std::cerr << "Resistor value must be greater than 0.\n";
    }
}

// Getter for resistor value
// Returns the current resistor value.
double Filter::get_resistor() const {
    return _resistor;
}

// Setter for capacitor value
// Ensures that the capacitor value is positive before setting it.
void Filter::set_capacitor(double capacitor) {
    if (capacitor > 0.0) {
        _capacitor = capacitor;
    } else {
        // Error message if the capacitor value is invalid
        std::cerr << "Capacitor value must be greater than 0.\n";
    }
}

// Getter for capacitor value
// Returns the current capacitor value.
double Filter::get_capacitor() const {
    return _capacitor;
}

// Calculate cutoff frequency
// Uses the formula f = 1 / (2 * π * R * C) to compute the cutoff frequency.
// Ensures resistor and capacitor values are valid before performing the calculation.
double Filter::calculate_cutoff() const {
    if (_resistor > 0.0 && _capacitor > 0.0) {
        const double pi = 3.141592653589793;
        return 1.0 / (2.0 * pi * _resistor * _capacitor);
    } else {
        // Error message if resistor or capacitor values are invalid
        std::cerr << "Resistor and capacitor values must be set and greater than 0.\n";
        return 0.0;
    }
}

// Output the result
// Displays the calculated cutoff frequency formatted to two decimal places.
void Filter::output_result() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The cutoff frequency is: " << calculate_cutoff() << " Hz\n";
}

// Validate filter type
// Helper function to check if the filter type is valid ("HP" or "LP").
bool Filter::isValidFilterType(const std::string& filter_type) {
    return filter_type == "HP" || filter_type == "LP";
}
