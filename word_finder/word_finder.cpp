#include <vector>
#include <iostream>
#include <string>

std::vector<std::string> shape_like(std::vector<std::string> original){
    for (int i = 0; i < original.size();i++){
        for (int j = 0; j < original[0].size(); j++){
            original[i][j] = '0';
        }
    }
    return original;
}


// (row, col) is the begining position. length is the length of the word
// direction = 0 means horizontally get the word, 1 means vertically
std::string get_word(
    int row, 
    int col, 
    int length, 
    bool direction, 
    const std::vector<std::string>& grid
){
    // std::cout << row << ' ' << col <<' '<<length<<' '<<direction<< std::endl;
    std::string word = "";
    if(!direction){
        for (int c = col; c < col + length;c++){
            if(c>=grid[0].size()){
                return "~";
            }
            word += grid[row][c];
        }
    }else{
        for (int r = row; r < row + length;r++){
            if(r>=grid.size()){
                return "~";
            }
            word += grid[r][col];
        }
    }
    return word;
}

bool find_word(
    const std::vector<std::string>& grid, 
    std::string word, 
    int& row, int& col, bool& direction
){
    int len = word.size();
    int max_row = grid.size();
    int max_col = grid[0].size();
    for (int r = 0; r < max_row;r++){
        for (int c = 0; c < max_col;c++){
            if(get_word(r, c, len, 0, grid) == word){
                row = r;
                col = c;
                direction = 0;
                return true;
            }
            if(get_word(r, c, len, 1, grid) == word){
                row = r;
                col = c;
                direction = 1;
                return true;
            }
        }

    }
    return false;
}


void find_words(
    const std::vector<std::string>& grid, 
    const std::vector<std::string>& words,
    std::vector<std::string>& solution,
    std::vector<std::string>& not_found
){
    auto mask = shape_like(grid);
    solution = shape_like(grid);
    for(auto word: words){
        int r, c, len = word.size();
        bool d;
        if(find_word(grid, word, r, c, d)){
            if(!d){ 
                // horizontal
                for (int j = c; j < c + len; j++){
                    mask[r][j] = '1';
                }
            }else{
                // vertical
                for (int i = r; i < r + len; i++)
                {
                    mask[i][c] = '1';
                }
            }
        }else{
            not_found.push_back(word);
        }
    }
    for (int i = 0; i < grid.size();i++){
        for (int j = 0; j < grid[1].size();j++){
            if(mask[i][j] == '1'){
                solution[i][j] = grid[i][j];
            }else{
                solution[i][j] = '#';
            }
        }
    }
}


int main(){

    std::vector<std::string> grid = {
        "xappleg",
        "dzeazkg",
        "zwazzbx",
        "dxnqzoy",
        "qyueytp",
        "pythtyg"
    };
    // std::cout << get_word(0, 0, 3, 0, grid);

    std::vector<std::string> words = {"peanut", "bot", "mango", "apple", "cinnamon"};
    std::vector<std::string> solution;
    std::vector<std::string> not_found;

    find_words(grid, words, solution, not_found); 

    std::vector<std::string> expected_solution = {
        "#apple#",
        "##e####",
        "##a##b#",
        "##n##o#",
        "##u##t#",
        "##t####"
    };

    std::vector<std::string> expected_not_found = {"mango", "cinnamon"};

    if( (solution == expected_solution) && (not_found == expected_not_found) ){
        std::cout << "test passed" << std::endl;
    }
    else{
        std::cout << "test failed" << std::endl;
    }

    std::cout << "solution:" << std::endl;
    for(int i = 0; i < solution.size(); i++){
        std::cout << solution[i] << std::endl;
    }

    std::cout << "not found:" << std::endl;
    for(int i = 0; i < not_found.size(); i++){
        std::cout << not_found[i] << std::endl;
    }

}