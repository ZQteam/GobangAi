#include <iostream>
#include "AI.h"

using namespace std;
int main() {
    CBoard a;
    int b[16][16];    // 棋盘固定大小为16X16
    a.SetChessman(5,5);
    a.SetChessman(6,6);
    a.SetChessman(7,7);
    a.GetBoard(b);
    for(int i=1; i<16; i++){
        for(int j=1; j<16; j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}