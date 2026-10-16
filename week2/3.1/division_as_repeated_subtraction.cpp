#include <iostream>

using namespace std;


int main(){
    double dividend, divisor, quotient, reminder;
    cout << "enter dividend & divisor\n";
    cin >> dividend >> divisor;
    while(dividend - divisor > 0){
        dividend -= divisor;
        quotient++;
    }
    reminder = dividend;
    cout << quotient << "R" << reminder;
    return 0;
}