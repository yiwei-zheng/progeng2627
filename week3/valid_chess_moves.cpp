#include <iostream>
using namespace std;
const int n_move[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
int main(){
    int nx, ny;
    int x, y;
    cout << "input the location of knigt: ";
    cin >> nx >> ny;
    cout << "input the target location: ";
    cin >> x >> y;
    if (x < 1 || x > 8 || y < 1 || y > 8)
    {
        cout << "invalid move\n";
        return 0;
    }
    bool check = 0;
    for (int i = 0; i < 8;i++){
        if (nx + n_move[i][0] == x && ny + n_move[i][1] == y){
            check = 1;
        }
    }
    if(check){
        cout << "valid move\n";
        return 0;
    }
    cout << "invalid move\n";
    return 0;
}