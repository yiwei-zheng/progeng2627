#include <iostream>
#include <fstream>
#include <string> 

int main(int argv, char* argc[]){
    std::string filename = argc[1];
    std::ifstream ifile;

    ifile.open(filename);
    if(!ifile.is_open()){
        std::cout << "failed to open the file given\n";
        return EXIT_FAILURE;
    }
    char c;
    while(ifile.get(c)){
        std::cout << c;
    }
    return 0;
}