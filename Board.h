//
// Created by 朱原熯 on 2017/5/16.
//

#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H


#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

struct point
{
    int x;
    int y;
    point(int xx = 0,int yy = 0):x(xx),y(yy){}
};

class CBoard
{
public:
    CBoard();
    ~CBoard();
    void Init(bool IsAiFirst = false);
    void GetBoard(char board[16][16]);
    void SetChessman(point s);
    void SetChessman(int x,int y);
    void SetChessman(int x,int y,char flag);
    void GetDfsPoint(vector<point> &DfsPoint);
    int GoBack();

private:
    char m_Board[16][16];
    vector<point> m_AiRecord;
    vector<point> m_ManRecord;
    bool m_IsAiFirstOffensive;
    bool m_IsAiSet;
};

#endif //UNTITLED_BOARD_H
