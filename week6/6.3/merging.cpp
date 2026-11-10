#include <iostream>
#include <vector>

void merge_vectors_int(const std::vector<int>& v1, const std::vector<int>& v2, std::vector<int>& vout){
    int s1 = v1.size();
    int s2 = v2.size();
    if(s1 > s2){
        merge_vectors_int(v2, v1, vout);
        return;
    }
    // thus we are sure that the size s1 < s2 :)

    int front_ptr1 = 0;
    int front_ptr2 = 0;
    while (front_ptr1 < s1 && front_ptr2 < s2){
        if(v1.at(front_ptr1) < v2.at(front_ptr2)){
            vout.push_back(v1.at(front_ptr1++));
        }else{
            vout.push_back(v2.at(front_ptr2++));
        }
    }
    if(front_ptr1 == s1){
        for (int i = front_ptr2; i < s2;i++){
            vout.push_back(v2.at(i));
        }
    }else{
        for (int i = front_ptr1; i < s1;i++){
            vout.push_back(v1.at(i));
        }
    }
    return;
}

void print_vec(std::vector<int> v){
    for(auto i: v){
        std::cout << i << ' ';
    }
}


int main(){

    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> out;

    std::vector<int> expected_output;

    v1 = {1, 3, 5, 6};
    v2 = {4, 6, 10};
    expected_output = {1, 3, 4, 5, 6, 6, 10};

    merge_vectors_int(v1, v2, out);
    // print_vec(out);

    if(out == expected_output){ // we can compare the content of vectors (at least in some cases)
        std::cout << "passed" << std::endl;
    }
    else{
        std::cout << "not passed" << std::endl;
    }
}