#include <iostream>

// function myswap to be used 
// in sort_two_numbers below
// must be included here (beforehand)

void sort_two_numbers(double& s1, double& s2){
    // complete this function
    // so that the output is as in the examples below

    // use function myswap within this function
    // (remember to change the type of the parameters to double)

    if (s2<s1){
        double tmp;
        tmp = s1;
        s1 = s2;
        s2 = tmp;
    }
    return;
}

void sort_three_numbers(double& s1, double& s2, double& s3){
    sort_two_numbers(s1, s2);
    sort_two_numbers(s2, s3);
    sort_two_numbers(s1, s2);
}

int main(){
    double n1, n2, n3;
    std::cout << "please enter three numbers:" << std::endl;
    std::cin >> n1 >> n2 >> n3;
    sort_three_numbers(n1, n2, n3);
    std::cout << n1 << " " << n2 << ' ' << n3 << std::endl;
}