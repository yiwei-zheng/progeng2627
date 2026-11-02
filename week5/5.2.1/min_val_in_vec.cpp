#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int min_vector_element(const vector<double>& vin){
    double min_val = 325799.114514;
    for(auto i: vin){
        min_val = min(i, min_val);
    }
    for (int i = 0; i < vin.size();i++){
        if(vin.at(i) == min_val){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<double> v{3, 2, 5, 7, 9};
    cout << min_vector_element(v);
    return 0;
}
