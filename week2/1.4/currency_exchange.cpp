#include <iostream>
#include <cstdio>
using namespace std;



int main(){
    double gbp;
    const double eur_per_gbp = 1.18;
    cout << "Input number of GBP: ";
    cin >> gbp;
    cout << "EUR = "<<gbp *eur_per_gbp;
    return 0;
}