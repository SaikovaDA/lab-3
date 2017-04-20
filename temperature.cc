#include"temperature.h"
Temperature convert(const Temperature& from, char to)
{

    double K, converted;
    Temperature tempr;
    switch (from.scale) {
    case 'K':
        K = from.temp;
        break;
    case 'F':
        K = (from.temp + 459.67) / 1.8;
        break;
    case 'C':
        K = (from.temp + 273.15);
        break;
    }

    switch (to) {
    case 'K':
        converted= K;
        break;
    case 'F':
        converted = (K*1.8)-459.67;
        break;
    case 'C':
        converted = K-273.15;
        break;
    }
    Temperature tempre;
    tempre.scale=converted;
    return tempre;
}


