//
// Created by 朱原熯 on 2017/5/11.
//

#include "chess_type.h"

using namespace std;
CChessType::CChessType() {
    type[0].shape = "01100";
    type[0].score = 1;
    type[1].shape = "01010";
    type[1].score = 1;
    type[2].shape = "010010";
    type[2].score = 1;
    type[3].shape = "211000";
    type[3].score = 1;
    type[4].shape = "21010";
    type[4].score = 1;
    type[5].shape = "210010";
    type[5].score = 1;
    type[6].shape = "01110";
    type[6].score = 1;
    type[7].shape = "010110";
    type[7].score = 1;
    type[8].shape = "211100";
    type[8].score = 1;
    type[9].shape = "211010";
    type[9].score = 1;
    type[10].shape = "011110";
    type[10].score = 1;
    type[11].shape = "10111";
    type[11].score = 1;
    type[12].shape = "211110";
    type[12].score = 1;
}

CChessType::~CChessType() {
}
void CChessType::Reverse(string s1, string s2, bool is_change)
{
    size_t len = s1.size();
    for(size_t i = len - 1; i < len; i++){
        s2 += s1[i];
    }
    if(is_change){
        for(size_t i=0; i<len; i++){
            if(s1[i] == 1) s1[i] = 2;
            if(s1[i] == 2) s1[i] = 1;
            if(s2[i] == 1) s2[i] = 2;
            if(s2[i] == 2) s2[i] = 1;
        }
    }
}
int CChessType::GetScore(string line, set<int> &hit, bool is_change) {
    string line2;
    Reverse(line, line2, is_change);
    int all_score = 0;
    for(int i=0;i<13;i++){
        if(line.find(type[i].shape) != string::npos || line2.find(type[i].shape) != string::npos){
            hit.insert(i);
            all_score += type[i].score;
        }
    }
    return all_score;
}

bool CChessType::is_in_board(int x, int y) {
    if(x > 0 && x < 16 && y > 0 && y < 16)
        return true;
    return false;
}

int CChessType::GetScore(int x, int y, char board[16][16], bool is_change) {
    int startx = x - 4;
    int starty = y - 4;
    int endx = x + 4;
    int endy = y + 4;
    cout << startx << " " << starty << " " << endx << " " << endy << endl;
    string str1 = "";
    string str2 = "";
    string str3 = "";
    string str4 = "";
    set<int> s1; s1.clear();
    set<int> s2; s2.clear();
    set<int> s3; s3.clear();
    set<int> s4; s4.clear();

    for(int i=startx, j=starty; i<=endx, j<=endy; i++,j++){
        if(is_in_board(i,j)) {
            str1 += board[i][j];
        }
    }
    int ss1 = GetScore(str1, s1, is_change);
    for(int i=startx, j=endy; i<=endx, j>=starty; i++,j--){
        if(is_in_board(i,j)) {
            str2 += board[i][j];
        }
    }
    int ss2 = GetScore(str2, s2, is_change);
    for(int i=startx,j=y; i<=endx ; i++){
        if(is_in_board(i,j)) {
            str3 += board[i][j];
        }
    }
    int ss3 = GetScore(str3, s3, is_change);
    for(int i=x,j=starty; j<=endy ; j++){
        if(is_in_board(i,j)) {
            str4 += board[i][j];
        }
    }
    int ss4 = GetScore(str4, s4, is_change);

    cout << str1 << " " << ss1 << endl;
    cout << str2 << " " << ss2 << endl;
    cout << str3 << " " << ss3 << endl;
    cout << str4 << " " << ss4 << endl;

    return ss1+ss2+ss3+ss4;
}

