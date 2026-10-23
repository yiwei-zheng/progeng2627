#include <iostream>
#include <string>
using namespace std;

void text_swap(string &a, string &b){
    string tmp = a;
    a = b;
    b = tmp;
    return;
}

int main(){
    string a = "aaa";
    string b = "bbb";
    text_swap(a, b);
    cout << a << ' ' << b;
    return 0;
}