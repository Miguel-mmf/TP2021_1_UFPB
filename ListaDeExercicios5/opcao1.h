#include <iostream>

template <class tipo> tipo convert_celsius_to_kelvin(tipo temp){return (temp + 273);}

template <class tipo> tipo convert_celsius_to_fahrenheit(tipo temp){return (1.8*temp + 32);}