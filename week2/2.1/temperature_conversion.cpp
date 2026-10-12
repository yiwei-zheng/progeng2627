#include <iostream>

using namespace std;



int main(){
    double deg1, deg2;
    char unit;
    cin >> deg1 >> unit;
    if(unit == 'F' || unit == 'f'){
        deg2 = (deg1 - 32) * 5 / 9;
        cout << deg2 << " C";
    }else if(unit == 'C' || unit == 'c'){
        deg2 = deg1 * 9 / 5 + 32;
        cout << deg2 << " F";
    }
    cout << "error, unit not recognised";
    return 0;
}
