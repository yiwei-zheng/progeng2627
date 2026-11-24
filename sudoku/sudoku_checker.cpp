#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>

// in this program we are going to represent the sudoku as a one dimensional vector
// linearised by row, for instance the 4x4 sudoku: 
// 1 2 3 4
// 4 1 2 76
// 4 4 4 1
// 9 4 1 -7
// will be represented as: 
// 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7

// function twod_to_oned maps two-dimensional indices to a one-dimensional one 
// it takes in input:
// - the two indices row and col of a two dimensional data structure
// - the length of the row, rowlen
// it returns:
// - the corresponding one-dimensional index

int twod_to_oned(int row, int col, int rowlen){
    return row * rowlen + col;
}

// function mfind
// takes in input:
// - a vector of integers v
// - an integer n
// returns:
// the index of the element n in v, if n is in v
// -1 if n is not in v
// for instance:
// v: 3 2 5; n: 2 | return: 1
// v: 3 1 2; n: -6 | return: -1
// v: 1 1 -12 1 5; n: 5 | return: 4

int mfind(int n, const std::vector<int>& v){
    // write your code here

    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] == n){
            return i;
        }
    }
    return -1;
}

// function check_sequence
// takes in input:
// - a vector of integers v
// returns:
// - true if v contains all the numbers from 1 to v.size() and false otherwise
// for instance:
// v: 3 2 5 | return: false
// v: 3 1 2 | return: true
// v: 1 1 -12 1 5 | return: false
// note that check_sequence must (meaningfully) use function mfind
bool check_sequence(const std::vector<int>& v){
    // write your code here
    for (int i = 1; i <= v.size(); i++)
    {
        int pos = mfind(i, v);
        if(pos == -1){
            return false;
        }
    }
    return true;
}

// function get_row
// takes in input:
// - a row index r
// - a one dimensional vector 'in' representing a sudoku
// provides in output:
// - a vector out containing the r-th row of in
// for example:
// r: 0; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 1 2 3 4
// r: 3; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 9 4 1 -7
// note that this function must (meaningfully) use function twod_to_oned
void get_row(int r, const std::vector<int>& in, std::vector<int>& out){
    // write your code here
    int a = sqrt(in.size());
    for (int i = 0; i < a;i++){
        out.push_back(in[twod_to_oned(r, i, a)]);
    }
}

// function get_col
// like get_row but for columns
// for example: 
// c: 0; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 1 4 4 9
// note that this function must (meaningfully) use function twod_to_oned
void get_col(int c, const std::vector<int>& in, std::vector<int>& out){
    // write your code here
    int a = sqrt(in.size());
    for (int i = 0; i < a; i++)
    {
        out.push_back(in[twod_to_oned(i, c, a)]);
    }
}

// function get_subsq
// like the two functions above but for subsquares
// we consider subsquares to be indexed from left to right
// and then from top to bottom 
// for example:
// subs: 0; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 1 2 4 1
// subs: 1; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 3 4 2 76
// subs: 2; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 4 4 9 4
// subs: 3; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 4 1 1 -7
// note that this function must (meaningfully) use function twod_to_oned
void get_subsq(int subs, const std::vector<int>& in, std::vector<int>& out){
    // write your code here
    int n = sqrt(in.size());

    // for each subsq, the side len is a_sub, there are also a_sub subsqs in each col/row
    int a_sub = sqrt(n);

    int subsq_row_begin = (subs / a_sub) * a_sub;
    int subsq_col_begin = (subs % a_sub) * a_sub;
    for (int i = subsq_row_begin; i < subsq_row_begin + a_sub; i++){
        for (int j = subsq_col_begin; j < subsq_col_begin + a_sub;j++){
            out.push_back(in[twod_to_oned(i, j, n)]);
        }
    }
}

// function valid_sudoku 
// takes in input:
// - a one dimensional vector representing a sudoku
// returns:
// - a boolean which is true if the sudoku is valid and false if it isn't valid

// write your code where indicated
// i.e. within the two remaining incomplete 'for' loops
// do not alter anything else

bool valid_sudoku(const std::vector<int>& g){
    int side = std::sqrt(g.size()); 
    std::vector<int> seq;

    // for each row...
    for(int i = 0; i < side; i++){
        seq.clear();
        get_row(i, g, seq);

        if(!check_sequence(seq)){ 
            return false;
        }
    }

    // for each column...
    for(int i = 0; i < side; i++){
        // write your code here
        seq.clear();
        get_col(i, g, seq);
        if(!check_sequence(seq)){
            return false;
        }
    }

    // for each subsquare...
    for(int i = 0; i < side; i++){
        // write your code here
        seq.clear();
        get_subsq(i, g, seq);
        if(!check_sequence(seq)){
            return false;
        }
    }

    // if the program execution gets to here it means that 
    // it hasn't executed a "return false" above
    // so the sudoku is valid:

    return true;
}

#define FLAG 1
#ifdef FLAG
int main(int argc, char* argv[]){

    if(argc != 2){
        std::cout << "one argument needed" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<int> s;

    // beginning of block of code reading the sudoku from the text file

    std::ifstream infile;
    infile.open(argv[1]);

    if(!infile.is_open()){
        std::cout << "error, can't open input file" << std::endl;
        return EXIT_FAILURE;
    }

    int tmp;

    while(infile >> tmp){
        s.push_back(tmp);
    }
    // end of block of code reading the sudoku from the text file
    // we now have the content of the sudoku in vector s

    int side = std::sqrt(s.size());
    // assuming it is a valid square grid in terms of size
    // (if it isn't, the program will not work properly, which is expected)

    // printing the content of the sudoku (as a square);
    // the sudoku is stored as a one-dimensional vector
    // but the vector can be indexed using two indices
    // by converting the indices of a two dimensional representation
    // into the corresponding one-dimensional index (using our function twod_to_oned)

    for(int i = 0; i < side; i++){
        for(int j = 0; j < side; j++){
            std::cout << s[twod_to_oned(i, j, side)] << " ";
        }
        std::cout << std::endl;
    }

    // calling the function checking if the sudoku is a valid one:

    bool valid = valid_sudoku(s);

    if(valid){
        std::cout << "valid" << std::endl;
    }
    else{
        std::cout << "not valid" << std::endl; 
    }

}

#endif


// void printvec(std::vector<int> v){
//     for(auto i: v){
//         std::cout << i << ' ';
//     }
// }


// int main(){
//     std::vector<int> v{1, 2, 3, 4, 4, 1, 2, 76, 4, 4, 4, 1, 9, 4, 1, -7};
//     std::vector<int> out;
//     get_subsq(3, v, out);
//     printvec(out);
// }





/*
  _   _ ____  ____    _____ ___    __  ____   ______  _____ _     _____ 
 | | | | __ )|  _ \  |_   _/ _ \  |  \/  \ \ / / ___|| ____| |   |  ___|
 | |_| |  _ \| | | |   | || | | | | |\/| |\ V /\___ \|  _| | |   | |_   
 |  _  | |_) | |_| |   | || |_| | | |  | | | |  ___) | |___| |___|  _|  
 |_| |_|____/|____/    |_| \___/  |_|  |_| |_| |____/|_____|_____|_|    
                                                                        
                 ( )
                  |
               ___|___
             .'       '.
            /___________\
            | ~ ~ ~ ~ ~ |
            |___________|
         .-'             '-.
        /___________________\
        |  \_/ \_/ \_/ \_/  |
        |                   |
        |___________________|
     .-'                     '-.
    /___________________________\
    |  \__/ \__/ \__/ \__/ \__/ |
    |                           |
    |       HAPPY BIRTHDAY      |
    |___________________________|
     \_________________________/
*/