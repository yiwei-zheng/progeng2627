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
int totient_sum(int n, int &depth){
    int sum = 0;
    depth = 0;
    while(n!=1){
        n = euler_totient(n);
        sum += n;
        depth++;
    }
    return sum;
}

int main(){
    int d = 0;
    cout << totient_sum(30, d) << endl
         << d << endl;
    return 0;
}
