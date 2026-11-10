#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

std::vector<std::string> a, b;
std::map<std::string, std::string> translator;
bool find(std::map<std::string, std::string> mp, std::string key){
    bool flag = 0;
    for(auto i: mp){
        if(key == i.first){
            flag = 1;
        }
    }
    return flag;
}

int main(){
    std::ifstream ad, rm;
    std::string tmp_a, tmp_b, tmp_ad;
    ad.open("ad.txt");
    rm.open("real_meaning.txt");
    if(!ad.is_open() || !rm.is_open()){
        std::cout << "error occured when handling file\n";
        return EXIT_FAILURE;
    }

    while (rm >> tmp_a && rm >> tmp_b){
        translator.insert({tmp_a, tmp_b});
    }
    while(ad >> tmp_ad){
        if(find(translator, tmp_ad)){
            std::cout << translator[tmp_ad] + ' ';
        }
        else{
            std::cout << tmp_ad + ' ';
        }
    }
    ad.close();
    rm.close();

    return 0;
}