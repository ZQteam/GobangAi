//
// Created by 朱原熯 on 2017/5/11.
//

#include "chess_type.h"

CChessType::CChessType() {
    type[0].shape = "01100";
    type[1].shape = "01010";
    type[2].shape = "010010";
    type[3].shape = "211000";
    type[4].shape = "21010";
    type[5].shape = "210010";
    type[6].shape = "01110";
    type[7].shape = "010110";
    type[8].shape = "211100";
    type[9].shape = "211010";
    type[10].shape = "011110";
    type[11].shape = "10111";
    type[12].shape = "211110";
}

CChessType::~CChessType() {

}

int CChessType::GetScore() {

    return 0;
}
