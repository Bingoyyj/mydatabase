//
// Created by 淼淼 on 2020/11/16.
//
#include "./json.hpp"
#define BLOCK 8
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
    bool readAll(int pos,int **p,int m,int n,char type);
    void writeAll(int **p,int m,int n,char type);
    void write(int *p,int n,char type);
    bool read(int pos,int *p,int n,char type);
    int readIndex(int *p,int n);
};
#endif //MYDB1_DATAHANDLER_H
