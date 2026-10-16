#include <iostream>

using namespace std;

int main(){
    int sum = 0;
    int num;
    while(1){
        cout << "enter a number:\n";
        cin >> num;
        sum += num;
        cout << "The sum so far is " << sum << endl;
    }
    return 0;
}