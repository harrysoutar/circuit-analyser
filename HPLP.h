#ifndef HPLP_H
#define HPLP_H

#include <string>

class Filter {
public:
    // Constructor
    Filter();

    // Setter for choosing high or low pass filter
    void set_filter(const std::string& filter_type);

    // Set and get for resistor value
    void set_resistor(double resistor);
    double get_resistor() const;

    // Set and get for capacitor values
    void set_capacitor(double capacitor);
    double get_capacitor() const;

    // Function for cutoff frequency
    double calculate_cutoff() const;

    // Function to output result
    void output_result() const;

    // Function to validate the filter type
    static bool isValidFilterType(const std::string& filter_type);

private:
    std::string _filter_type;
    double _resistor{0.0};
    double _capacitor{0.0};
};

#endif // HPLP_H
