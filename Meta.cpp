//
// Created by 淼淼 on 2020/11/16.
//

#include "Meta.h"
#include "StatusCode.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <direct.h>
#include <stack>
Meta::Meta() {
    usedDB="";
    usedTB="";
    load();
}

Meta::~Meta() {
    usedDB="";
    usedTB="";
    save();
}

void Meta::load() {
    ifstream i("../meta.json");
    i>>j;
    i.close();
}

void Meta::save() {
    ofstream o("../meta.json");
    o<<setw(4)<<j<<endl;
    o.close();
}

void Meta::createDB(string name) {
    if(findDB(name)){
        cout<<EXIST_DATABASE<<endl;
    }else{
        j[name]={};
        mkdir(("../data/"+name).c_str());
        cout<<SUCCESS_CREATE_DATABASE<<endl;
    }
}

void Meta::dropDB(string name) {
    if(!findDB(name)){
        cout<<NOT_FOUND_DATABASE<<endl;
    }else{
        string temp=usedDB;
        usedDB=name;
        stack<string> s;
        for (auto& el:j[name].items()){
            s.push(el.key());
        }
        while(!s.empty()){
            dropTB(s.top());
            s.pop();
        }
        if(temp==name){
            usedDB="";
        }else{
            usedDB=temp;
        }
        rmdir(("../data/"+name).c_str());
        j.erase(name);
        cout<<SUCCESS_DROP_DATABASE<<endl;
    }
}

bool Meta::findDB(string name) {
    for (auto& el:j.items()) {
        if(el.key()==name){
            return true;
        }
    }
    return false;
}

bool Meta::useDB(string name) {
    if(!findDB(name)){
        cout<<NOT_FOUND_DATABASE<<endl;
        return false;
    }else{
        usedDB=name;
        cout<<USE_DATABASE<<endl;
        return true;
    }
}

void Meta::showDB() {
    for (auto& el:j.items()) {
        cout<<el.key()<<endl;
    }
}

void Meta::createTB(string name) {
    if(usedDB.empty()){
        cout<<NOT_USE_DATABASE<<endl;
    }else if(findTB(name)){
        cout<<NOT_FOUND_TABLE<<endl;
    }else{
        int n;cin>>n;
        auto *p=new string[n];
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        j[usedDB][name]={{"columns",{}},{"primaryKey",p[0]},{"count",n}};
        for(int i=0;i<n;i++){
            j[usedDB][name]["columns"][p[i]]={i};
        }
        ofstream f("../data/"+usedDB+"/"+name+'H');
        f.close();
        cout<<SUCCESS_CREATE_TABLE<<endl;
    }
}

void Meta::dropTB(string name) {
    if(usedDB.empty()){
        cout<<NOT_USE_DATABASE<<endl;
    }else if(!findTB(name)){
        cout<<NOT_FOUND_TABLE<<endl;
    }else{
        j[usedDB].erase(name);
        remove(("../data/"+usedDB+"/"+name+'H').c_str());
        remove(("../data/"+usedDB+"/"+name+'C').c_str());
        cout<<SUCCESS_DROP_TABLE<<endl;
    }
}

bool Meta::findTB(string name) {
    for (auto& el:j[usedDB].items()) {
        if(el.key()==name){
            return true;
        }
    }
    return false;
}

bool Meta::useTB(string name) {
    if(usedDB.empty()){
        cout<<NOT_USE_DATABASE<<endl;
        return false;
    }else if(!findTB(name)){
        cout<<NOT_FOUND_TABLE<<endl;
        return false;
    }else{
        usedTB=name;
        cout<<USE_TABLE<<endl;
        return true;
    }
}

void Meta::showTB() {
    if(usedDB.empty()){
        cout<<NOT_USE_DATABASE<<endl;
    }else{
        for (auto& el:j[usedDB].items()) {
            cout<<el.key()<<endl;
        }
    }
}

int Meta::getN() {
    return j[usedDB][usedTB]["count"];
}















