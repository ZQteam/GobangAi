//
// Created by 朱原熯 on 2017/5/16.
//

#include "Board.h"
using namespace std;
CBoard::CBoard(){}

CBoard::~CBoard(){}

void CBoard::GetBoard(char board[16][16])
{
    for(int i=1; i<16; i++){
        for(int j=1; j<16; j++){
            board[i][j] = m_Board[i][j];
        }
    }
}

void CBoard::Init(bool IsAiFirst) {
    //初始化记录表 用于记录棋路
    m_AiRecord.clear();
    m_ManRecord.clear();
    m_IsAiFirstOffensive = IsAiFirst;
    m_IsAiSet = IsAiFirst;
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            m_Board[i][j] = '0';
        }
    }
}

void CBoard::SetChessman(point s)
{
    if(m_IsAiSet){
        m_AiRecord.push_back(s);
        m_Board[s.x][s.y] = m_IsAiFirstOffensive ? '1' : '2';
        m_IsAiSet = false;
    }
    else{
        m_ManRecord.push_back(s);
        m_Board[s.x][s.y] = m_IsAiFirstOffensive ? '2' : '1';
        m_IsAiSet = true;
    }
}

void CBoard::SetChessman(int x,int y)
{
    point a(x,y);
    SetChessman(a);
}

int CBoard::GoBack()
{
    if(m_ManRecord.size() && m_AiRecord.size()){
        auto it1 = m_AiRecord.end() - 1;
        auto it2 = m_ManRecord.end() - 1;
        m_Board[(*it1).x][(*it1).y] = 0;
        m_Board[(*it2).x][(*it2).y] = 0;
        m_ManRecord.pop_back();
        m_AiRecord.pop_back();
        return 0;
    }
    return -1;
}

void CBoard::GetDfsPoint(vector<point> &DfsPoint) {
    point ok_point;
    int f[24][2] = {{0,1},{0,2},{0,-1},{0,-2},
                    {1,0},{1,1},{1,2},{1,-1},{1,-2},
                    {2,0},{2,1},{2,2},{2,-1},{2,-2},
                    {-1,0},{-1,1},{-1,2},{-1,-1},{-1,-2},
                    {-2,0},{-2,1},{-2,2},{-2,-1},{-2,-2}};
    for(int i=1; i<16; i++){
        for(int j=1; j<16; j++){
            bool is_ok = false;
            for(int k=0; k<24; k++){
                int x = i + f[k][0];
                int y = j + f[k][1];
                if(x > 0 && x < 16 && y > 0 && y < 16 && (m_Board[x][y] == '1' || m_Board[x][y] == '2')){
                    is_ok = true;
                    break;
                }
            }
            if(is_ok && m_Board[i][j] == '0') {
                ok_point.x = i;
                ok_point.y = j;
                DfsPoint.push_back(ok_point);
            }
        }
    }
    return ;
}

void CBoard::SetChessman(int x, int y, char flag) {
    m_Board[x][y] = flag;
}

