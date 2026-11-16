#include <vector>
#include <iostream>

unsigned long next_calalan(const std::vector<unsigned long>& c){
    unsigned long c_next = 0;
    int n = c.size();
    for (int i = 0; i < n;i++){
        c_next += c[i] * c[n - i - 1];
    }
    return c_next;
}

std::vector<unsigned long> catalan_numbers(int n){
    std::vector<unsigned long> c;
    c.push_back(1);
    for (int i = 1; i <= n;i++){
        c.push_back(next_calalan(c));
    }
    return c;
}
int main(){
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    auto c = catalan_numbers(n);
    for (auto i = 0; i < c.size();i++)
    {
        std::cout << "C" << i << " = " << c[i] << '\n';
    }
}