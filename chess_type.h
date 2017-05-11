//
// Created by 朱原熯 on 2017/5/11.
//

#ifndef UNTITLED_CHESS_TYPE_H
#define UNTITLED_CHESS_TYPE_H

#include <string>
#include <vector>

struct Type {
    string shape;
    int score;
};

class CChessType {
public:

    CChessType();
    ~CChessType();
    int GetScore();

private:
    Type type[13];
};

#endif //UNTITLED_CHESS_TYPE_H
