//
// Created by Jan on 2020/12/31.
//
#include<iostream>
using namespace std;
#ifndef MYDB1_NODE_H
#define MYDB1_NODE_H
class AvlNode{
    friend ostream& operator<<(ostream &out, AvlNode &n);
public:
    int primaryKey;
    int index;
    AvlNode();
    AvlNode(int primaryKey, int index);
    AvlNode& operator=(AvlNode &n);
    bool operator==(AvlNode &n);
    bool operator>(AvlNode &n);
    bool operator<(AvlNode &n);
};
#endif //MYDB1_NODE_H
