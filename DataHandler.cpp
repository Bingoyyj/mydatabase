//
// Created by 淼淼 on 2020/11/16.
//

#include "DataHandler.h"
#include <fstream>
#include <iostream>
using namespace std;
DataHandler::DataHandler(string dbName, string tbName,int size){
    this->dbName=dbName;
    this->tbName=tbName;
    this->size=size;
}

bool DataHandler::readAll(int pos,int **p,int m,int n,char type) {
    ifstream inFile("../data/"+dbName+"/"+tbName+type,ios::binary);
    inFile.seekg(pos*sizeof(int)*n);
    int temp;
    int i=0;
    while(inFile.read((char *) &temp, sizeof(int))){
        if(i%n==0){
            p[i/n]=new int[n];
        }
        p[i/n][i%n]=temp;
        i++;
        if(i==m*n){
            bool isContinue=bool(inFile.read((char *) &temp, sizeof(int)));
            inFile.close();
            return isContinue;
        }
    }
    inFile.close();
    return false;
}

void DataHandler::writeAll(int **p,int m,int n,char type) {
    ofstream outFile("../data/"+dbName+"/"+tbName+type, ios::app | ios::binary);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            outFile.write((char*)&p[i][j], sizeof(int));
        }
    }
    outFile.close();
}

int DataHandler::readIndex(int *p,int n) {
    ifstream inFile("../data/"+dbName+"/"+tbName+'C',ios::binary);
    int temp,i=0;
    while(inFile.read((char *) &temp, sizeof(int))){
        p[i++]=temp;
        inFile.seekg(int(inFile.tellg())+(n-1)*sizeof(int)+(BLOCK-1)*n*sizeof(int));
    }
    return i;
}

bool DataHandler::read(int pos, int *p, int n, char type) {
    ifstream inFile("../data/"+dbName+"/"+tbName+type,ios::binary);
    inFile.seekg(pos*sizeof(int)*n);
    int temp;
    for(int i=0;i<n;i++){
        if(inFile.read((char *) &temp, sizeof(int))){
            p[i]=temp;
        }else{
            return false;
        }
    }
    return true;
}

void DataHandler::write(int *p, int n, char type) {
    ofstream outFile("../data/"+dbName+"/"+tbName+type, ios::app | ios::binary);
    for(int i=0;i<n;i++){
        outFile.write((char*)&p[i], sizeof(int));
    }
    outFile.close();
}


