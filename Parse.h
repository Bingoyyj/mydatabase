//
// Created by Jan on 2020/12/14.
//
#include "Meta.h"
#include "DataHandler.h"
#include "Handler.h"
using namespace std;
#ifndef MYDB1_PARSE_H
#define MYDB1_PARSE_H
class Parse{
private:
    Meta meta;
    DataHandler* dataHandler;
    Handler *handler;
    string usedDB;
    string usedTB;
    int n;
public:
    Parse();
    void input();
    void show();
    void create();
    void use();
    void drop();
    void search();
    void insert();
    void remove();
    void alter();
    ~Parse();

};
#endif //MYDB1_PARSE_H
