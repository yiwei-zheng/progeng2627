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

int euler_totient(int n){
    int cnt = 0;
    for (int i = 1; i <= n;i++){
        if (gcd(i, n) == 1){
            cnt++;
        }
    }
    return cnt;
}


int main(){
    cout << euler_totient(9) << endl
         << euler_totient(12) << endl
         << euler_totient(17);
    return 0;
}