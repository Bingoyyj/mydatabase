//
// Created by Jan on 2020/12/31.
//

#include "Handler.h"

Handler::Handler(string usedDB,string usedTB,int n):usedDB(usedDB),usedTB(usedTB),n(n){
    num=0;
    numH=0;
    dataHandler=new DataHandler(usedDB,usedTB,n);
    loadHotData();
}

void Handler::loadHotData() {
    avl=new AVL<AvlNode>;
    p=new int*[2*MAXLINE];
    for(int i=0;i<2*MAXLINE;i++){
        p[i]=nullptr;
    }
    dataHandler->readAll(0,p,2*MAXLINE,n,'H');
    for(int i=0;i<2*MAXLINE;i++){
        if(p[i]==nullptr){
            break;
        }
        avl->insert(AvlNode(p[i][0],i));
        num++;
        numH++;
    }
}

int* Handler::search(int primaryKey) {
    auto temp=avl->search(AvlNode(primaryKey, 0));
    if(temp){
//        cout<<temp->key.primaryKey<<' '<<temp->key.index<<endl;
        int *pSearch=new int[n];
        dataHandler->read(temp->key.index, pSearch, n, 'H');
        return pSearch;
    }else{
        return searchColdData(primaryKey);
    }
}

int* Handler::searchColdData(int primaryKey) {
    int *pIndex=new int[MAXLINE];
    int count=dataHandler->readIndex(pIndex, n);
    pIndex[count]=INT_MAX;
    int foundIndex=-1;
    int low = 0;
    int high = count-1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (pIndex[mid] <= primaryKey && primaryKey < pIndex[mid + 1]){
            foundIndex=mid;
            break;
        }else if (pIndex[mid] > primaryKey){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    delete []pIndex;
    if(foundIndex==-1){
        return nullptr;
    }
    int **pBlock=new int*[BLOCK];
    for(int i=0;i<BLOCK;i++){
        pBlock[i]=new int[n];
    }
    dataHandler->readAll(foundIndex*BLOCK, pBlock, BLOCK, n, 'C');

    foundIndex=-1;
    low = 0;
    high = BLOCK-1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if (pBlock[mid][0] == primaryKey){
            foundIndex=mid;
            break;
        }else if (pBlock[mid][0] > primaryKey){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    if(foundIndex==-1){
        return nullptr;
    }else{
        return pBlock[foundIndex];
    }
}

void Handler::merge() {
    int mergeNum=num-MAXLINE;
    if(mergeNum<=0){
        return;
    }
    AVL<AvlNode> avlMerge;
    for(int i=0;i<mergeNum;i++){
        avlMerge.insert(AvlNode(p[i][0], i));
    }

    AvlNode *q;
    q=avlMerge.inorder(mergeNum);

    int **p1,**p2;
    p1=new int*[mergeNum];
    p2=new int*[MAXLINE];
    for(int i=0;i<mergeNum;i++){
        p1[i]=new int[3];
        dataHandler->read(q[i].index,p1[i],n,'H');
    }
    bool continueToRead;
    int position=0;
    int count1=0;
    do{
        for(int i=0;i<MAXLINE;i++){
            p2[i]=nullptr;
        }
        int count2=0;
        continueToRead=dataHandler->readAll(position,p2,MAXLINE,n,'C');
        while(count1<mergeNum && (count2<MAXLINE && p2[count2]!=nullptr)){
            if(p1[count1][0]<p2[count2][0]){
                dataHandler->write(p1[count1],n,'D');
                count1++;
            }else{
                dataHandler->write(p2[count2],n,'D');
                count2++;
            }
        }
        if(count1<mergeNum && !continueToRead){
            while(count1<mergeNum){
                dataHandler->write(p1[count1],n,'D');
                count1++;
            }
        }else{
            while(count2<MAXLINE && p2[count2]!=nullptr){
                dataHandler->write(p2[count2],n,'D');
                count2++;
            }
        }
        position+=MAXLINE;
    } while(continueToRead);
    for(int i=0;i<mergeNum;i++){
        delete []p1[i];
    }
    for(int i=0;i<MAXLINE;i++){
        delete []p2[i];
    }
    delete []p1;
    delete []p2;
    int **p3;
    p3=new int*[MAXLINE];
    for(int i=0;i<MAXLINE;i++){
        p3[i]=p[MAXLINE+i];
    }
    dataHandler->writeAll(p3,MAXLINE,n,'I');
    remove(("../data/"+usedDB+"/"+usedTB+'H').c_str());
    remove(("../data/"+usedDB+"/"+usedTB+'C').c_str());
    rename(("../data/"+usedDB+"/"+usedTB+'I').c_str(),("../data/"+usedDB+"/"+usedTB+'H').c_str());
    rename(("../data/"+usedDB+"/"+usedTB+'D').c_str(),("../data/"+usedDB+"/"+usedTB+'C').c_str());
}

void Handler::print(char type) {
    int count=0;
    int **s=new int*[MAXLINE];
    bool continueToRead=false;
    int position=0;
    do{
        for(int i=0;i<MAXLINE;i++){
            s[i]=nullptr;
        }
        continueToRead=dataHandler->readAll(position,s,MAXLINE,n,type);
        for(int i=0;i<MAXLINE;i++){
            if(s[i]==nullptr){
                break;
            }
            for(int j=0;j<n;j++){
                cout<<s[i][j]<<' ';
            }
            cout<<endl;
            count++;
        }
        position+=MAXLINE;
    } while(continueToRead);
    cout<<count<<endl;
    for(int i=0;i<MAXLINE;i++){
        delete []s[i];
    }
    delete []s;
}

Handler::~Handler() {
    save();
    if(p){
        for(int i=0;i<2*MAXLINE;i++){
            if(p[i]){
                delete []p[i];
                p[i]=nullptr;
            }else{
                break;
            }
        }
        delete p;
        p=nullptr;
    }
    delete dataHandler;
}

bool Handler::insert(int *pInsert) {
    if(search(pInsert[0])!=nullptr){
        return false;
    }
    p[num]=pInsert;
    avl->insert(AvlNode(p[num][0],numH));
    dataHandler->write(pInsert,n,'H');
    num++;
    numH++;
    if(num==2*MAXLINE){
        save();
        merge();
        for(int i=0;i<MAXLINE;i++){
            if(p[i]){
                delete []p[i];
                p[i]=nullptr;
            }
        }
        delete []p;
        p=nullptr;
        num=0;
        numH=0;
        delete avl;
        loadHotData();
    }
    return true;
}

bool Handler::removeNode(int primaryKey) {
    int index=-1;
    for(int i=0;i<num;i++){
        if(p[i][0]==primaryKey){
            index=i;
            break;
        }
    }
    if(index==-1){
        return false;
    }else{
        avl->remove(AvlNode(primaryKey,0));
        for(int i=index;i<num;i++){
            p[i]=p[i+1];
        }
        num--;
        return true;
    }
}

void Handler::save() {
    remove(("../data/"+usedDB+"/"+usedTB+'H').c_str());
    dataHandler->writeAll(p,num,n,'H');
}

void Handler::display() {
    int count=0;
    for(int i=0;i<num;i++){
        for(int j=0;j<n;j++){
            cout<<p[i][j]<<' ';
        }
        count++;
        cout<<endl;
    }
    cout<<count<<endl;
}
