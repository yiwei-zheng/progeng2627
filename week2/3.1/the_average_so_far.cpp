#include <iostream>

using namespace std;

int main(){
    double sum = 0, cnt = 1;
    double num;
    while(1){
        cout << "enter a number:\n";
        cin >> num;
        sum += num;
        double avg = sum / cnt;
        cout << "The average so far is " << avg << endl;
        cnt++;
    }
    return 0;
}