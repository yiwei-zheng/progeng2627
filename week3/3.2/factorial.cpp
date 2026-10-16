#include <iostream>

using namespace std;


int main(){
    int n;
    cout << "enter n: \n";
    cin >> n;
    int res = 1;
    for (int i = n; i >= 1;i--){
        res *= i;
    }
    cout << "n! = " << res;
    return 0;
}