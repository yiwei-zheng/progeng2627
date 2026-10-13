#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// for all functions here, we assume that x0, y0, x1, y1 are valid
bool n_check(int x0, int y0, int x1, int y1){
    const int valid_moves[8][2] = {
        {1, 2},
        {1, -2},
        {-1, 2},
        {-1, -2},
        {2, 1},
        {2, -1},
        {-2, 1},
        {-2, -1}
    };

    int dx = x1 - x0;
    int dy = y1 - y0;
    int move[2] = {dx, dy};
    bool result = 0;
    for (int i = 0; i < 8;i++){
        if (valid_moves[i][0] == move[0] && valid_moves[i][1] == move[1]){
            result = 1;
            break;
        }
    }
    return result;
}
bool r_check(int x0, int y0, int x1, int y1){
    return x0 == x1 ^ y0 == y1;
}
bool b_check(int x0, int y0, int x1, int y1){
    int dx = x1 - x0;
    int dy = y1 - y0;
    return (dy == dx || dy + dx == 0) && dy != 0 && dx != 0;
}
bool q_check(int x0, int y0, int x1, int y1){
    return b_check(x0, y0, x1, y1) || r_check(x0, y0, x1, y1);
}
bool k_check(int x0, int y0, int x1, int y1){
    int dx = x1 - x0;
    int dy = y1 - y0;
    return q_check(x0, y0, x1, y1) && (abs(dx) == 1 || abs(dy) == 1);
}

int main(){
    char piece;
    int x0, y0, x1, y1;
    bool result = 0;
    cout << "enter the chess piece: ";
    cin >> piece;
    cout << "enter initial position and final position: ";
    cin >> x0 >> y0 >> x1 >> y1;
    if (x0 < 1 || x0 > 8 || y0 < 1 || y0 > 8 || x1 < 1 || x1 > 8 || y1 < 1 || y1 > 8){
        cout << "invalid move\n";
        return 0;
    }

    if (piece == 'n'){
        result = n_check(x0, y0, x1, y1);
    }else if (piece == 'r'){
        result = r_check(x0, y0, x1, y1);
    }else if (piece == 'b'){
        result = b_check(x0, y0, x1, y1);
    }else if (piece == 'q'){
        result = q_check(x0, y0, x1, y1);
    }else if (piece == 'k'){
        result = k_check(x0, y0, x1, y1);
    }
    if (result){
        cout << "valid move";
        return 0;
    }
    cout << "invalid move";
    return 0;
}