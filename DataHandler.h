//
// Created by 淼淼 on 2020/11/16.
//
#include "./json.hpp"
using json=nlohmann::json;
using namespace std;
#ifndef MYDB1_DATAHANDLER_H
#define MYDB1_DATAHANDLER_H
class DataHandler{
    string dbName;
    string tbName;
    int size;
public:
    DataHandler(string dbName,string tbName,int size);
    void read(int pos,int *p,int n);
    void write(int *p,int n);
};
#endif //MYDB1_DATAHANDLER_H
