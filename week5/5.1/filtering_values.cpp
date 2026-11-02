#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    vector<int> arr;
    cin >> n;
    while(n--){
        int elmt;
        cin >> elmt;
        arr.push_back(elmt);
    }
    int threshod;
    cin >> threshod;
    for(auto i:arr){
        if(i < threshod){
            cout << i << ' ';
        }
    }
    return 0;
}