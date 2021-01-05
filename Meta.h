//
// Created by 淼淼 on 2020/11/16.
//
#include "./json.hpp"
using namespace std;
using json=nlohmann::json;
#ifndef MYDB1_META_H
#define MYDB1_META_H
class Meta{
private:
    json j;
    string usedDB;
    string usedTB;
public:
    Meta();
    ~Meta();
    void load();
    void save();
    void createDB(string name);
    void dropDB(string name);
    bool findDB(string name);
    bool useDB(string name);
    void showDB();

    void createTB(string name);
    void dropTB(string name);
    bool findTB(string name);
    bool useTB(string name);
    void showTB();
    int getN();
};
#endif //MYDB1_META_H
