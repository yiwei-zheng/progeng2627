#include <iostream>

using namespace std;

bool is_prime(int n){
    for (int i = 2; i * i <= n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

void prime_in_range(int beg, int end){
    for (int i = beg; i <= end;i++){
        if(is_prime(i)){
            cout << i << '\n';
        }
    }
}

int main(){
    int a, b;
    cin >> a >> b;
    prime_in_range(a, b);
    return 0;
}