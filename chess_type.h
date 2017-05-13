//
// Created by 朱原熯 on 2017/5/11.
//

#ifndef UNTITLED_CHESS_TYPE_H
#define UNTITLED_CHESS_TYPE_H

#include <string>
#include <vector>
#include <string>
using namespace std;
struct Type {
    std::string shape;
    int score;
};

class CChessType {
public:
    CChessType();
    ~CChessType();
    int GetScore(string line,bool is_change = false);

private:
    void Reverse(string s1, string s2, bool is_chenge);

private:
    Type type[13];
};

#endif //UNTITLED_CHESS_TYPE_H
