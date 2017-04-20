#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
#include"temperature.h"
using namespace std;
void test_temperature_input(){
    Temperature tempr;
    istringstream issK("10K");
    issK>>tempr;
    assert(tempr.temp ==10);
    assert(tempr.scale =='K');
    istringstream issF("10F");
    issF>>tempr;
    assert(tempr.temp ==10);
    assert(tempr.scale =='F');
    istringstream issC("10C");
    issC>>tempr;
    assert(tempr.temp ==10);
    assert(tempr.scale =='C');

}
int main()
{

    Temperature tempr;
    cout<<tempr.scale;
    cout<<tempr.temp;
    cin>>tempr;

    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    vector<Temperature>temperatures(item.count)
    vector<double> temperature(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cin >> temperature[i];
    }

    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;
    double min = temperature[0];
    double max = temperature[0];
    for (double number : temperature) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }
    vector<size_t> counts(column_count);
    for (Temperature temperature : temperatures) {
        const double Kelvins=convert(temperature,'K').scale;
        const double max_K=convert(max,'K').scale;
        const double min_K=convert(min,'K').scale;
        size_t column = (size_t)((Kelvins - min_K) / (max_K - min_K) * column_count);
        if (column == column_count) {
            column--;
        }
        counts[column]++;
    }

    const size_t screen_width = 80;
    const size_t axis_width = 4;
    const size_t chart_width = screen_width - axis_width;

    // Можно было бы считать в предыдущем цикле, но так более наглядно.
    size_t max_count = 0;
    for (size_t count : counts) {
        if (count > max_count) {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > chart_width;

    for (size_t count : counts) {
        if (count < 100) {
            cout << ' ';
        }
        if (count < 10) {
            cout << ' ';
        }
        cout << count << "|";

        size_t height = count;
        if (scaling_needed) {
            const double scaling_factor = (double)chart_width / max_count;
            height = (size_t)(count * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}