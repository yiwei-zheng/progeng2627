#include <iostream>

using namespace std;

double max2(double num1, double num2){
    if (num1< num2){
        return num2;
    }
    return num1;
}


int main(){
    cout << max2(10, 15)<<endl;
    cout << max2(19, 3) << endl;
    return 0;
}