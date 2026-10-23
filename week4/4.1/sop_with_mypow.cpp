#include <iostream>
using namespace std;

double mypow(double base, int exp){
    double result = 1; 
    // we declare a variable for the result
    // (should it be initialised? to what value?)
    if(exp < 0){
        base = 1.0 / base;
        exp = -exp;
    }

    for (int i = 0; i < exp;i++)
        result *= base;
        // TODO: use a for loop to implement the repeated multiplication algorithm
        // so that at the end of the loop variable result contains base^exp

        return result;
    // at the end we return the value we computed
    // we *do not print* anything in the function
}

double sum_of_powers(double x, int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum += mypow(x, i);
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