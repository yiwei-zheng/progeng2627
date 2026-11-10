#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int search_vector(std::string s, const std::vector<std::string>& vin){
    for (int i = 0; i < vin.size() - 1;i++){
        if (vin.at(i) == s){
            return i;
        }
    }
    return -1;
}
void union_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    vout = vin1;
    for(auto i: vin2){
        if (search_vector(i, vin1) == -1){
            vout.push_back(i);
        }
    }
}

void intersection_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    for(auto i: vin1){
        if(search_vector(i, vin2) != -1){
            vout.push_back(i);
        }
    }
}



int main(){
    // warehouse 1 and 2, intersection and union
    std::vector<std::string> w1, w2, intsc_vec, un_vec;
    // input object for warehouse1 and warehouse 2
    std::ifstream w1i, w2i;
    // output object for intersection and union
    std::ofstream intsc, un;
    w1i.open("warehouse1.txt");
    w2i.open("warehouse2.txt");
    intsc.open("intersection.txt");
    un.open("union.txt");

    if(!(w1i.is_open() && w2i.is_open() && intsc.is_open() && un.is_open())){
        std::cout << "error in opening files\n";
        return EXIT_FAILURE;
    }


    std::string line1, line2;
    while(w1i>>line1){
        w1.push_back(line1);
    }
    while(w2i>>line2){
        w2.push_back(line2);
    }
    w1i.close();
    w2i.close();

    union_vector(w1, w2, un_vec);
    intersection_vector(w1, w2, intsc_vec);

    for(auto i: un_vec){
        un << i << '\n';
    }
    for(auto i:intsc_vec){
        intsc << i << '\n';
    }
    std::cout << "DONE\n";
    return 0;
}