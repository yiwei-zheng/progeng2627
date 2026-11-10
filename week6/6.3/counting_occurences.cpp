#include <iostream>
#include <fstream>
#include <vector> 
#include <string>


int main(){
    std::ifstream text, words;
    text.open("text.txt");

    words.open("words.txt");

    if(!text.is_open() || ! words.is_open()){
        std::cout << "error occurs when handling files";
        return EXIT_FAILURE;
    }
    std::string word, content;
    std::vector<std::string> dict;
    std::vector<int> occr;

    while(words >> word){
        dict.push_back(word);
        occr.push_back(0);
    }

    while (text >> content)
    {
        for (int i = 0; i < dict.size();i++){
            if(dict.at(i) == content){
                occr[i]++;
            }
        }
    }
    for (int i = 0; i < dict.size(); i++)
    {
        std::cout << dict[i] << ": " << occr[i] << '\n';
    }
    return 0;
}