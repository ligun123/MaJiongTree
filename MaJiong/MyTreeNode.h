//
//  MyTreeNode.h
//  MaJiong
//
//  Created by Kira on 10/9/12.
//  Copyright (c) 2012 Kira. All rights reserved.
//

#ifndef __MaJiong__MyTreeNode__
#define __MaJiong__MyTreeNode__

#include <iostream>
#include "GGPoint.h"

class MyTreeNode {
private:
    MyTreeNode *firstChild;        //第一个孩子节点
    MyTreeNode *nextBrother;       //下一个兄弟节点
    MyTreeNode *parentNode;
public:
    GGPoint Position;
    MyTreeNode(GGPoint value, MyTreeNode *fc = NULL, MyTreeNode *ns = NULL, MyTreeNode *pa = NULL):Position(value),firstChild(fc),nextBrother(ns), parentNode(pa){
        if (pa){
            pa->FirstChild()->addBrother(this);
        }
    };
    virtual ~MyTreeNode();
    
    //getter & setter
    MyTreeNode *FirstChild();
    MyTreeNode *NextBrother();
    MyTreeNode *ParentNode();
    void setFirstChild(MyTreeNode *node);
    void setNextBrother(MyTreeNode *node);
    void setParentNode(MyTreeNode *node);
    
    MyTreeNode *NodeForValue(GGPoint p);        //查找值p的节点
    
    //add child & brother
    void addChildNode(MyTreeNode *child);       //添加子节点
    void addBrother(MyTreeNode *brother);       //添加兄弟节点
    
    bool isEqualTo(MyTreeNode *node);           //判断两节点是否相等
    bool isEqualPP(GGPoint p1, GGPoint p2);     //判断量ggpoint相等
    bool isHasBrotherValue(GGPoint p);        //判断node中的值是否已存在自己的brother中
    void display();                             //打印自身数据
};

#endif /* defined(__MaJiong__MyTreeNode__) */
