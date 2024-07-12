#include <iostream>
#include <iomanip> // for std::setprecision

using namespace std;

// Function prototypes
double celsiusToFahrenheit(double celsius);
double celsiusToKelvin(double celsius);
double fahrenheitToCelsius(double fahrenheit);
double fahrenheitToKelvin(double fahrenheit);
double kelvinToCelsius(double kelvin);
double kelvinToFahrenheit(double kelvin);

int main() {
    double temperature;
    char unit;

    // Prompt the user for input
    cout << "Enter the temperature value: ";
    cin >> temperature;
    cout << "Enter the unit of measurement (C for Celsius, F for Fahrenheit, K for Kelvin): ";
    cin >> unit;

    cout << fixed << setprecision(2); // Set precision for output

    // Perform conversions based on the unit of measurement
    switch (unit) {
        case 'C':
        case 'c':
            cout << "Temperature in Fahrenheit: " << celsiusToFahrenheit(temperature) << " F" << endl;
            cout << "Temperature in Kelvin: " << celsiusToKelvin(temperature) << " K" << endl;
            break;
        case 'F':
        case 'f':
            cout << "Temperature in Celsius: " << fahrenheitToCelsius(temperature) << " C" << endl;
            cout << "Temperature in Kelvin: " << fahrenheitToKelvin(temperature) << " K" << endl;
            break;
        case 'K':
        case 'k':
            cout << "Temperature in Celsius: " << kelvinToCelsius(temperature) << " C" << endl;
            cout << "Temperature in Fahrenheit: " << kelvinToFahrenheit(temperature) << " F" << endl;
            break;
        default:
            cout << "Invalid unit of measurement." << endl;
            break;
    }

    return 0;
}

// Function definitions
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0 + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32;
}
