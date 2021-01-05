//
// Created by Jan on 2020/12/31.
//

#include "AvlNode.h"

AvlNode::AvlNode(): primaryKey(0), index(0){}
AvlNode::AvlNode(int primaryKey, int index): primaryKey(primaryKey), index(index){}
AvlNode &AvlNode::operator=(AvlNode &n) {
    this->primaryKey=n.primaryKey;
    this->index=n.index;
    return *this;
}
bool AvlNode::operator==(AvlNode &n){
    return this->primaryKey==n.primaryKey;
}
bool AvlNode::operator>(AvlNode &n){
    return this->primaryKey>n.primaryKey;
}
bool AvlNode::operator<(AvlNode &n) {
    return this->primaryKey<n.primaryKey;
}
ostream& operator<<(ostream &out, AvlNode &n){
    out<<n.primaryKey<<' '<<n.index<<endl;
    return out;
}