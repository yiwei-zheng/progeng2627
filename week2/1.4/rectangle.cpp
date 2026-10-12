#include <iostream>

using namespace std;

int main(){
    double a, b;
    cin >> a >> b;
    int c = 2 * (a + b);
    int s = a * b;
    cout << "Perimeter is " << c << endl;
    cout << "Area is " << s << endl;
    return 0;
}