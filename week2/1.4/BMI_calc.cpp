#include <iostream>

using namespace std;


int main(){
    double h, w, bmi;
    cout << "please input your height in m: ";
    cin >> h;
    cout << "please input your weight in kg: ";
    cin >> w;
    bmi = w / (h * h);
    cout << "your BMI is " << bmi << endl;
    return 0;
}