#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double a, b, c;

    cout << "Enter three side lengths: ";
    cin >> a >> b >> c;

    // Check whether the sides form a valid triangle

    // If valid:
    //   Determine and display the type of triangle
    //   Calculate and display the perimeter
    //   Calculate and display the area using Heron's formula

    // Otherwise:
    //   Display a message saying the triangle is invalid
    if ((a + b > c) && (a + c > b) && (b + c > a) && a > 0 && b > 0 && c > 0){
        if ((a == b) || (b == c) || (a == c)){
            if(a == b && b == c){
                cout << "equilateral\n";
            }else{
                cout << "isosceles\n";
            }
        }else{
            cout << "scalene\n";
        }
            cout << "perimeter = " << a + b + c << endl;
        int s = 1 / 2 * (a + b + c);
        int area = sqrt(s * (s - a) * (s - b) * (s - c));
    cout << "area = " << area << endl;
    }
    else
    {
        cout << "not a valid triangle\n";
    }
    return 0;
}