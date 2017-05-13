//
// Created by 朱原熯 on 2017/5/11.
//

#ifndef UNTITLED_CHESS_TYPE_H
#define UNTITLED_CHESS_TYPE_H

#include <string>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
struct Type {
    std::string shape;
    int score;
};

class CChessType {
public:
    CChessType();
    ~CChessType();
    int GetScore(int x, int y, int board[16][16]);
private:
    int GetScore(string line, vector<int> & hit, bool is_change = false);
    void Reverse(string s1, string s2, bool is_chenge);
    bool is_in_board(int x, int y);

private:
    Type type[13];
};

#endif //UNTITLED_CHESS_TYPE_H
