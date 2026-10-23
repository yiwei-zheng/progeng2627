#include <iostream>

using namespace std;

double max2(double num1, double num2){
    if (num1< num2){
        return num2;
    }
    return num1;
}

double max3(double a, double b, double c){

    return max2(max2(a, b), c);
}


int main(){
    cout << max3(1, 2, 3) << endl;
    cout << max3(7, 9, 8) << endl;
    cout << max3(10, 0, 1) << endl;
}
