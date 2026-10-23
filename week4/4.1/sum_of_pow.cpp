#include <iostream>
#include <math.h>


using namespace std;

double sum_of_powers(double x, int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum += pow(x, i);
    }
    return sum;
}

int main(){
    double x;
    int n;
    cin >> x >> n;
    cout << sum_of_powers(x, n);
    return 0;
}