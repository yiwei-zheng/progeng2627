#include <iostream>
using namespace std;

int gcd(int a, int b){
    int remainder = 325799;
    while(1){
        remainder = a % b;
        a = b;
        if(remainder == 0){
            break;
        }
        b = remainder;
    }
    return b;
}

int main(){
    cout << gcd(48, 18);
    return 0;
}