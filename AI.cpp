//
// Created by 朱原熯 on 2017/5/11.
//

#include "AI.h"
using namespace std;
CBoard::CBoard(bool IsAiFirst)
{
    //初始化记录表 用于记录棋路
    m_AiRecord.clear();
    m_ManRecord.clear();
    m_IsAiFirstOffensive = IsAiFirst;
    m_IsAiSet = IsAiFirst;
}

CBoard::~CBoard(){}

void CBoard::GetBoard(int board[16][16])
{
    for(int i=1; i<16; i++){
        for(int j=1; j<16; j++){
            board[i][j] = m_Board[i][j];
        }
    }
}

void CBoard::SetChessman(point s)
{
    if(m_IsAiSet){
        m_AiRecord.push_back(s);
        m_Board[s.x][s.y] = m_IsAiFirstOffensive ? 1 : 2;
        m_IsAiSet = false;
    }
    else{
        m_ManRecord.push_back(s);
        m_Board[s.x][s.y] = m_IsAiFirstOffensive ? 2 : 1;
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