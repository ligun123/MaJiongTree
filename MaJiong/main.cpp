//
//  main.cpp
//  MaJiong
//
//  Created by Kira on 10/9/12.
//  Copyright (c) 2012 Kira. All rights reserved.
//

#include <iostream>
#include "MyTree.h"

#define X_ROW 7
#define Y_LIST 10

int maps[X_ROW][Y_LIST] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,2,2,2,2,2,2,1,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,2,0,0,0,2,0,0},
    {0,0,0,0,0,0,0,2,0,0},
    {0,1,0,0,2,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0}};

MyTreeNode *rootNode = new MyTreeNode(GGPoint(2,1));       //起始节点,要找到起对应的可相连的节点
MyTree *tree = new MyTree(rootNode);

//...Functions...
GGPoint *pointsConnectWithPoint(GGPoint p);                 //返回所有和p直线相连的点
bool canConnectWithPoint(GGPoint pBegin, GGPoint pEnd);     //两点是否直线相连


//Main function
int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    
    delete tree;
    return 0;
}

GGPoint *pointsConnectWithPoint(GGPoint p)                 //返回所有和p直线相连的点
{
    GGPoint *pArray = (GGPoint *)calloc(X_ROW+Y_LIST, sizeof(GGPoint));
    pArray[0] = GGPoint(1,1);
    return NULL;
}

bool canConnectWithPoint(GGPoint pBegin, GGPoint pEnd)
{
    if (pBegin.x != pEnd.x && pBegin.y != pEnd.y) {
        return false;
    }
    
    if (pBegin.x == pEnd.x) {
        //TODO
    }
    
    if (pBegin.y == pEnd.y) {
        //TODO
    }
}
