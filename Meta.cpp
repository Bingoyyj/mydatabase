//
// Created by 淼淼 on 2020/11/16.
//

#include "Meta.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <direct.h>
Meta::Meta() {
    usedDB="";
    load();
}

Meta::~Meta() {
    usedDB="";
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
        cout<<"failed"<<endl;
    }else{
        j[name]={};
        mkdir(("../data/"+name).c_str());
        cout<<"Succeeded"<<endl;
    }
}

void Meta::dropDB(string name) {
    if(!findDB(name)){
        cout<<"failed"<<endl;
    }else{
        j.erase(name);
        if(usedDB==name){
            usedDB="";
        }
        rmdir(("../data/"+name).c_str());
        cout<<"Succeeded"<<endl;
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

void Meta::useDB(string name) {
    if(!findDB(name)){
        cout<<"failed"<<endl;
    }else{
        usedDB=name;
    }
}

void Meta::createTB(string name) {
    if(usedDB.empty()){
        cout<<"failed1"<<endl;
    }else if(findTB(name)){
        cout<<"failed2"<<endl;
    }else{
        j[usedDB][name]={{"columns",{}},{"primaryKey",""}};
//        mkdir(("../data/"+usedDB+"/"+name).c_str());
        cout<<"Succeeded"<<endl;
    }
}

void Meta::dropTB(string name) {
    if(usedDB.empty()){
        cout<<"failed1"<<endl;
    }else if(!findTB(name)){
        cout<<"failed2"<<endl;
    }else{
        j[usedDB].erase(name);
//        rmdir(("../data/"+usedDB+"/"+name).c_str());
        cout<<"Succeeded"<<endl;
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

void Meta::addCL(string tbName, string clName) {
    if(usedDB.empty()){
        cout<<"failed1"<<endl;
    }else if(!findTB(tbName)){
        cout<<"failed2"<<endl;
    }else if(findCL(tbName,clName)){
        cout<<"failed3"<<endl;
    }
    else{
        j[usedDB][tbName]["columns"][clName]={j[usedDB][tbName]["columns"].size()};
        cout<<"Succeeded"<<endl;
    }
}

void Meta::dropCL(string tbName, string clName) {
    if(usedDB.empty()){
        cout<<"failed1"<<endl;
    }else if(!findTB(tbName)){
        cout<<"failed2"<<endl;
    }else if(!findCL(tbName,clName)){
        cout<<"failed3"<<endl;
    }
    else{
        j[usedDB][tbName]["columns"].erase(clName);
        cout<<"Succeeded"<<endl;
    }
}

bool Meta::findCL(string tbName,string clname) {
    for (auto& el:j[usedDB][tbName]["columns"].items()) {
        cout<<el.key()<<' '<<clname<<endl;
        if(el.key()==clname){
//            cout<<el.key()<<endl;
            return true;
        }
    }
    return false;
}











