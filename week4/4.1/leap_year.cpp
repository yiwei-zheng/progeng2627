#include <iostream>

using namespace std;


bool leap_year(int year){
    if (year % 4 == 0){
        if(year % 400 == 0){
            return 1;
        }else if (year % 100 ==0){
            return 0;
        }
        return 1;
    }
    return 0;
}


int main(){
    std::cout << (leap_year(1600) == true) << std::endl;
    std::cout << (leap_year(1700) == false) << std::endl;
}