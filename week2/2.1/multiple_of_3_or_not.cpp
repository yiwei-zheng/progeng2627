#include <iostream>

using namespace std;


int main(){
    bool mul_of_3;
    int n;
    cout << "please enter a number: ";
    cin >> n;
    mul_of_3 = n % 3 == 0;
    if (mul_of_3){
        cout << "the number is a multiple of 3";
    }else{
        cout << "the number is not a multiple of 3";
    }
    return 0;
}