#include <iostream>
using namespace std;

int main(){
    int min, max;
    cout << "enter the range (min, max) :\n";
    cin >> min >> max;
    while(1){
        int guess = (min + max) / 2;
        cout << "is it " << guess << "?\n";
        string ans;
        cin >> ans;
        if (ans == "yes"){
            break;
        }else if (ans == "smaller"){
            max = guess;
        }else if (ans == "larger"){
            min = guess;
        }

    }
    return 0;
}
