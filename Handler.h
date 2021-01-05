//
// Created by Jan on 2020/12/31.
//
#include "AVL.h"
#include "AvlNode.h"
#include "DataHandler.h"
#include <fstream>
#define MAXLINE 100
#ifndef MYDB1_HANDLER_H
#define MYDB1_HANDLER_H
class Handler{
    string usedDB;
    string usedTB;
    int n;
    int num;
    int countRemove;
    int numH;
    AVL<AvlNode>* avl;
    DataHandler* dataHandler;
    int **p;
public:
    Handler(string usedDB,string usedTB,int n);
    void loadHotData();
    void merge();
    int* search(int primaryKey);
    int* searchColdData(int primaryKey);
    void print(char type);
    void display();
    bool insert(int *pInsert);
    bool removeNode(int primaryKey);
    void save();
    ~Handler();
};

#endif //MYDB1_HANDLER_H
