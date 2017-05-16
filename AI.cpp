//
// Created by 朱原熯 on 2017/5/11.
//

#include "AI.h"
using namespace std;

Ai::~Ai() {}


point Ai::GetSetPos() {
    node start;
    vector<point> DfsPoint;
    bd.GetBoard(board);
    bd.GetDfsPoint(DfsPoint);
    if(DfsPoint.empty()){
        return point(8,8);
    }
    size_t len = DfsPoint.size();
    for(size_t i=0; i<len; i++){
        start.from = point(DfsPoint[i].x,DfsPoint[i].y);

    }
    start.score = 0;
    start.deep = 0;
    dfs(start);
}

int Ai::dfs(node x) {
    bool is_ai = false;
    vector<point> DfsPoint;
    if(x.deep % 2 == 0)
        is_ai = true;
    bd.GetDfsPoint(DfsPoint);

    return 0;
}

Ai::Ai(CBoard &b) {
    bd = b;
}

