#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> a, b;
std::string translate(std::string raw){
    int s = a.size();
    for (int i = 0; i < s;i++){
        if(raw == a[i]){
            return b[i];
        }
    }
    return "";
}


int main(){
    std::ifstream ad, rm;
    std::string tmp_a, tmp_b;
    while (rm >> tmp_a && rm >> tmp_b){
        a.push_back(tmp_a);
        b.push_back(tmp_b);
    }


    return 0;
}