//
// Created by 淼淼 on 2020/11/16.
//

#include "DataHandler.h"
#include <fstream>
#include <iostream>
using namespace std;
DataHandler::DataHandler(string dbName, string tbName,int size) {
    this->dbName=dbName;
    this->tbName=tbName;
    this->size=size;
}

void DataHandler::read(int pos,int *p,int n) {
    ifstream inFile("../data/"+dbName+"/"+tbName);
//    cout<<sizeof(j)<<endl;
    inFile.seekg(pos*sizeof(int));
//    string str;
    for(int i=0;i<n;i++){
        inFile.read((char*)&p[i], sizeof(int));
    }

//    cout<<j<<endl;
//    cout<<string(c)<<endl;
//    j=json::parse(string(c));
    inFile.close();
}

void DataHandler::write(int* p,int n) {
    ofstream outFile("../data/"+dbName+"/"+tbName, ios::app | ios::binary);
    for(int i=0;i<n;i++){
        outFile.write((char*)&p[i], sizeof(int));
    }
//    outFile.write()
    outFile.close();
}


