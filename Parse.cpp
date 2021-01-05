//
// Created by Jan on 2020/12/14.
//

#include "Parse.h"
#include "StatusCode.h"
#include <iostream>
Parse::Parse() {
    dataHandler= nullptr;
    handler= nullptr;
    n=0;
    cout<<WELCOME<<endl;
}

void Parse::input() {
    string op;
    while(cout<<"myDatabse>" && cin>>op){
        if(op=="show"){
            show();
        }else if(op=="create"){
            create();
        }else if(op=="use"){
            use();
        }else if(op=="drop"){
            drop();
        }else if(op=="exit"){
            cout<<EXIT<<endl;
            break;
        }else if(op=="search"){
            search();
        }else if(op=="print"){
            char type;cin>>type;
            handler->print(type);
        }else if(op=="insert"){
            insert();
        }else if(op=="remove"){
            remove();
        }else if(op=="alter"){
            alter();
        }else if(op=="display"){
            handler->display();
        }else{
            cout<<ILLEGAL_INPUT<<endl;
        }
    }
}

void Parse::show() {
    string obj;
    cin>>obj;
    if(obj=="databases"){
        meta.showDB();
    }else if(obj=="tables"){
        meta.showTB();
    }else{
        cout<<ILLEGAL_INPUT_SHOW<<endl;
    }
}

void Parse::create() {
    string obj,name;
    cin>>obj>>name;
    if(obj=="database"){
        meta.createDB(name);
    }else if(obj=="table"){
        meta.createTB(name);
    }else{
        cout<<ILLEGAL_INPUT_OBJECT<<endl;
    }
}

void Parse::use() {
    string obj,name;
    cin>>obj>>name;
    if(obj=="database"){
        if(meta.useDB(name)){
            usedDB=name;
            usedTB="";
            if(handler){
                delete handler;
                handler=nullptr;
            }
        }
    }else if(obj=="table"){
        if(meta.useTB(name)){
            usedTB=name;
            n=meta.getN();
            if(handler){
                delete handler;
                handler=nullptr;
            }
            handler=new Handler(usedDB,name,n);
        }
    }else{
        cout<<ILLEGAL_INPUT_OBJECT<<endl;
    }
}

void Parse::drop() {
    string obj,name;
    cin>>obj>>name;
    if(obj=="database"){
        meta.dropDB(name);
    }else if(obj=="table"){
        meta.dropTB(name);
    }else{
        cout<<ILLEGAL_INPUT_OBJECT<<endl;
    }
}

void Parse::search() {
    if(usedDB.empty()){
        cout<<NOT_USE_DATABASE<<endl;
    }else if(usedTB.empty()){
        cout<<NOT_USE_TABLE<<endl;
    }else{
        int primaryKey;cin>>primaryKey;
        int *p=handler->search(primaryKey);
        if(p){
            for(int i=0;i<n;i++){
                cout<<p[i]<<' ';
            }
            cout<<endl;
        }else{
            cout<<NOT_FOUND_DATA<<endl;
        }
    }
}

Parse::~Parse() {
    delete handler;
    delete dataHandler;
}

void Parse::insert() {
    if(usedDB.empty()){
        cout<<NOT_USE_DATABASE<<endl;
    }else if(usedTB.empty()){
        cout<<NOT_USE_TABLE<<endl;
    }else{
        int *p=new int[n];
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        if(handler->insert(p)){
            cout<<SUCCESS_INSERT<<endl;
        }else{
            cout<<EXIST_DATA<<endl;
        }
    }
}

void Parse::remove() {
    if(usedDB.empty()){
        cout<<NOT_USE_DATABASE<<endl;
    }else if(usedTB.empty()){
        cout<<NOT_USE_TABLE<<endl;
    }else{
        int primaryKey;cin>>primaryKey;
        if(handler->removeNode(primaryKey)){
            cout<<SUCCESS_REMOVE<<endl;
        }else{
            cout<<FAIL_REMOVE<<endl;
        }
    }
}

void Parse::alter() {
    if(usedDB.empty()){
        cout<<NOT_USE_DATABASE<<endl;
    }else if(usedTB.empty()){
        cout<<NOT_USE_TABLE<<endl;
    }else{
        int *p=new int[n];
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        if(handler->removeNode(p[0])){
            handler->insert(p);
            cout<<SUCCESS_ALTER<<endl;
        }else{
            cout<<FAIL_ALTER<<endl;
        }
    }
}
