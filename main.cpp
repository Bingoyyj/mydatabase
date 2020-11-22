#include <iostream>
#include <fstream>
#include "Meta.h"
#include "DataHandler.h"
#include "json.hpp"
using namespace std;
using json=nlohmann::json;
//class CStudent
//{
//public:
//    char szName[20];
//    int age;
//};
int main()
{
////    CStudent s{};
//    json j;
//    j["name"]="test";
//    j["age"]=18;
//    ofstream outFile("../data/table1", ios::out | ios::binary);
////    int t;cin>>t;
//    outFile.write((char*)&j, sizeof(j));
////    while (t--){
////        cin >> s.szName >> s.age;
////        outFile.write((char*)&s, sizeof(s));
////    }
////    while (t--){
////        cin >> j["name"] >> j["age"];
////        outFile.write((char*)&j, sizeof(j));
////    }
////    cin>>s.szName>>s.age;
////    outFile.seekp(sizeof(s)*2);
////    outFile.write((char*)&s, sizeof(s));
//    outFile.close();
//    ifstream inFile("../data/table1",ios::in|ios::binary);
//    if(!inFile) {
//        cout << "error" <<endl;
//        return 0;
//    }
////    cout<<"hello"<<endl;
////    while(inFile.read((char *)&s, sizeof(s))) {
//////        int readedBytes = inFile.gcount();
////        cout << s.szName << " " << s.age << endl;
////    }
////    while(inFile.read((char *)&j, sizeof(j))) {
//////        int readedBytes = inFile.gcount();
////        cout << j["name"] << " " << j["age"] << endl;
////    }
////    inFile.seekg(sizeof(s));
////    inFile.read((char *)&s, sizeof(s));
//    inFile.read((char *)&j, sizeof(j));
//    cout<<j["name"]<<' '<<j["age"]<<endl;
////    cout << s.szName << " " << s.age << endl;
//    inFile.close();
    Meta meta;
//    meta.createDB("database1");
    meta.useDB("database1");
//    meta.createTB("table1");
//    meta.addCL("table1","id");
//    meta.addCL("table1","name");
//    meta.addCL("table1","age");
    DataHandler dataHandler("database1","table1",3*sizeof(int));
//    json jw;
//    jw["id"]=2019150001;
//    jw["name"]=123;
//    jw["age"]="20";
//    int *p=new int[3];
//    p[0]=2019047035;
//    p[1]=123;
//    p[2]=20;
//    dataHandler.write(p,3);
//    cout<<sizeof(jw)<<endl;
//    json jr;
    int *q=new int[3];
    dataHandler.read(0,q,3);
    for(int i=0;i<3;i++){
        cout<<q[i]<<endl;
    }
//    cout<<jr["id"]<<' '<<jr["name"]<<' '<<jr["age"]<<endl;
//    ifstream i("meta.json");
//    json j;
//    i >> j;
    return 0;
}