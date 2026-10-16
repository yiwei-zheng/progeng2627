#include <iostream>
#include <string>
using namespace std;
int main(){
    string n;

    std::cin >> n;

    while(n!="STOP"){
        std::cout << n << std::endl;
        std::cin >> n;
    }
}