//
// Created by 朱原熯 on 2017/5/11.
//

#ifndef UNTITLED_AI_H
#define UNTITLED_AI_H
#include "Board.h"
#include "chess_type.h"
using namespace std;
struct node
{
    point from;
    int score;
    int deep;
};
class Ai
{
public:
    Ai(CBoard &b);
    ~Ai();
    point GetSetPos();

private:
    CBoard bd;
    CChessType tp;
    char board[16][16];
    int dfs(node x);
};

#endif //UNTITLED_AI_H
