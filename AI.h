//
// Created by 朱原熯 on 2017/5/11.
//

#ifndef UNTITLED_AI_H
#define UNTITLED_AI_H

#include <vector>
#include <string>
#include <cstring>
using namespace std;

struct point
{
    int x;
    int y;
    point(int xx,int yy):x(xx),y(yy){}
};

class CBoard
{
public:
    CBoard(bool IsAiFirst = false);
    ~CBoard();
    void GetBoard(char board[16][16]);
    void SetChessman(point s);
    void SetChessman(int x,int y);
    int GoBack();

private:
    char m_Board[16][16];
    vector<point> m_AiRecord;
    vector<point> m_ManRecord;
    bool m_IsAiFirstOffensive;
    bool m_IsAiSet;
};

#endif //UNTITLED_AI_H
