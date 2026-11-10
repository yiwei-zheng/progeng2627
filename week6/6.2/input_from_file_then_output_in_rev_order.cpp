#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

int main(){
    std::ifstream infile; 
    infile.open("input.txt");

    std::vector<int> v;

    if(!infile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    int tmp;

    while(infile >> tmp){
        v.push_back(tmp); 
        // instead of printing the values
        // as in the example above
        // first we store them in a vector
    }

    infile.close(); 

    // TODO: print the content of v in reversed order
    // onto a different text file
    std::ofstream outfile;
    outfile.open("output.txt");
    if(!outfile.is_open()){
        std::cout << "error opening file\n";
        return EXIT_FAILURE;
    }

    for (int i = v.size() - 1; i >= 0;i--){
        outfile << v.at(i) << '\n';
    }
    outfile.close();
    std::cout << "DONE\n";
    return 0;
}