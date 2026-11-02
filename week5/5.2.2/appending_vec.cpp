#include <iostream>

#include <vector>

using namespace std;
void append_vectors(const std::vector<int>& vin1, const std::vector<int>& vin2, std::vector<int>& vout){
    vout = vin1;
    for(auto i: vin2){
        vout.push_back(i);
    }
}


int main(){
    vector<int> a{1, 2, 3, 4, 5}, b{10, 9, 8, 7};
    vector<int> c;
    append_vectors(a, b, c);
    for(auto i: c){
        cout << i << ' ';
    }
    return 0;
}
