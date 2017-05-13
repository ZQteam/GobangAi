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
int CChessType::GetScore(string line,bool is_change) {
    string line2;
    Reverse(line, line2, is_change);
    //for(int i=0;i<13;i++){
    //
    //}
    return 0;
}
