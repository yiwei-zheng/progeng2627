#include <iostream>

using namespace std;


int main(){
    double c, f;
    cout << "Input degree Celcius: ";
    cin >> c;
    f = c * 9 / 5 + 32;
    cout << "it is " << f << "F";
    return 0;
}