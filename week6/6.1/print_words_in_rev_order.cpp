#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(){
    std::vector<std::string> container;
    std::ifstream file;
    file.open("input.txt");

    if(!file.is_open()){
        std::cout << "error in opening file\n";
        return 0;
    }

    std::string buffer;
    while(file>>buffer){
        container.push_back(buffer);
    }
    for (int i = container.size() - 1; i >= 0;i--){
        std::cout << container.at(i) << std::endl;
    }
    return 0;
}