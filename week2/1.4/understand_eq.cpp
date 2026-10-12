#include <iostream>

int main(){
    double a, b, c;

    a = 1;
    b = 2;
    c = a + b;

    std::cout << c << std::endl;
    // this line will print 3

    a = 2;

    // this line will print 3
    std::cout << c << std::endl;
    // TODO: before testing the program
    // write in a comment below
    // what you expect to be printed

    c = a + b;
    // this line will print 4
    std::cout << c << std::endl;
    // TODO: before testing the program
    // write in a comment below
    // what you expect to be printed
}