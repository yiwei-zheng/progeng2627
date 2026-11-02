#include <iostream>
#include <vector>
using namespace std;


int search_vector(int n, const vector<int>& vin){
    for (int i = 0; i < vin.size();i++){
        if(n == vin.at(i)){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> v{3, 2, 5, 7, 9};
    cout << search_vector(5, v);
    return 0;
}