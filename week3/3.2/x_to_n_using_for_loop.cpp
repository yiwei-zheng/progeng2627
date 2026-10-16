#include <iostream>
using namespace std;

int main(){
    int x, n;
    cout << "enter x and n: \n";
    cin >> x >> n;
    int res = 1;
    for (int i = 0; i < n;i++){
        res *= x;
    }
    cout << "result is " << res;
    return 0;
}