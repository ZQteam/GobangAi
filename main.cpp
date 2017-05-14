#include <iostream>
#include "AI.h"
#include "chess_type.h"
using namespace std;
int main() {
    CBoard a;
    CChessType c;
    char b[16][16];    // 棋盘固定大小为16X16
    a.SetChessman(5,5);
    a.SetChessman(3,3);
    a.SetChessman(7,7);
    a.SetChessman(1,1);
    a.SetChessman(6,6);
    a.GetBoard(b);
    int score = c.GetScore(5,5,b);
    cout << score << endl;
    for(int i=1; i<16; i++){
        for(int j=1; j<16; j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}