#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr;
    int n;
    cout << "please enter n:\n";
    cin >> n;
    while(n--){
        int a;
        cout << "please enter a number:\n";
        cin >> a;
        arr.push_back(a);
    }
    cout << "please enter s:\n";
    int s, cnt = 0;
    cin >> s;
    for(auto i: arr){
        if(i == s){
            cnt++;
        }
    }
    cout << "there are " << cnt << " occurences of " << s << endl;
    return 0;
}
