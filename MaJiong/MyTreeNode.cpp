//
//  MyTreeNode.cpp
//  MaJiong
//
//  Created by Kira on 10/9/12.
//  Copyright (c) 2012 Kira. All rights reserved.
//

#include "MyTreeNode.h"
//getter & setter

MyTreeNode::~MyTreeNode()
{//destroy me 
}
MyTreeNode *MyTreeNode::FirstChild()
{
    return firstChild;
}
MyTreeNode *MyTreeNode::NextBrother()
{
    return nextBrother;
}
MyTreeNode *MyTreeNode::ParentNode()
{
    return parentNode;
}
void MyTreeNode::setFirstChild(MyTreeNode *node)
{
    firstChild = node;
}
void MyTreeNode::setNextBrother(MyTreeNode *node)
{
    nextBrother = node;
}
void MyTreeNode::setParentNode(MyTreeNode *node)
{
    parentNode = node;
}

//add child & brother
void MyTreeNode::addChildNode(MyTreeNode *child)
{
    if (child == NULL) {
        std::cout<<"child == NULL"<<std::endl;
        return;
    }
    if (firstChild == NULL) {
        firstChild = child;
        firstChild->setParentNode(this);
    } else {
        firstChild->addBrother(child);
    }
}
void MyTreeNode::addBrother(MyTreeNode *brother)
{
    if (brother == NULL) {
        std::cout<<"brother == NULL"<<std::endl;
    }
    if (nextBrother == NULL) {
        nextBrother = brother;
        nextBrother->setParentNode(parentNode);
    } else {
        MyTreeNode *tempNode = nextBrother;
        while (tempNode->NextBrother()) {
            tempNode = tempNode->NextBrother();
        }
        tempNode->setNextBrother(brother);
        tempNode->NextBrother()->setParentNode(parentNode);
    }
}


MyTreeNode *MyTreeNode::NodeForValue(GGPoint p)
{
    printf("p(%d,%d)\n",p.x,p.y);
    if (isEqualPP(Position, p)) {
        return this;
    }
    MyTreeNode *tempNode = this;
    if (tempNode->NextBrother() != NULL) {
        MyTreeNode *findNode = tempNode->NextBrother()->NodeForValue(p);
        if (findNode) {
            return findNode;
        }
    }
    if (tempNode->FirstChild() != NULL) {
        MyTreeNode *findNode = tempNode->FirstChild()->NodeForValue(p);
        if (findNode) {
            return findNode;
        }
    }
    return NULL;
}

bool MyTreeNode::isEqualTo(MyTreeNode *node)
{
    if (isEqualPP(Position, node->Position)) {
        return true;
    } else return false;
}

bool MyTreeNode::isEqualPP(GGPoint p1, GGPoint p2)
{
    if (p1.x == p2.x && p1.y == p2.y) {
        return true;
    } else return false;
}

bool MyTreeNode::isHasBrotherValue(GGPoint p)
{
    MyTreeNode *tempNode = this;
    while (tempNode) {
        if (isEqualPP(tempNode->Position, p)) {
            return true;
        }
        tempNode = tempNode->NextBrother();
    }
    return false;
}

void MyTreeNode::display()
{
    printf("P(%d,%d)\n",Position.x, Position.y);
}
