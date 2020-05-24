//
//  main.cpp
//  dsa_work
//
//  Created by LiweiGu on 2020/5/14.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

/*
实现一个程序根据二叉树的前序，中序序列，给出后序序列
要求

输入
前序序列（以逗号隔开）
中序序列（以逗号隔开）

输出
后序序列（以逗号隔开）
*/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct tree {
    int data;
    tree *_left = NULL;
    tree *_right = NULL;
};

// 将 string 序列 转换为 vector
void toVector(string str, vector<int> *vct);
void buildTree(tree *_t, const vector<int> _pre, const vector<int> _right);
void postorder(struct tree* t, vector<int> *vct);

int main(int argc, const char * argv[]) {
    // 输入序列
    string _pre, _mid;
    vector<int> v_pre, v_mid;
    
    cout<< "请输入前序序列:" <<endl;
    cin >> _pre;
    toVector(_pre, &v_pre);
    
    cout << "请输入中序序列:" <<endl;
    cin >> _mid;
    toVector(_mid, &v_mid);
    
    tree *t = (tree *)malloc(sizeof(tree));
    buildTree(t, v_pre, v_mid);
    vector<int> pos;
    postorder(t, &pos);
    for(int i=0; i<pos.size()-1; i++) {
        cout << pos[i] << ",";
    }
    cout << pos[pos.size()-1] << endl;
}


void toVector(string str, vector<int> *vct){
    for(int i=0; i<str.length(); i++){
        if(str[i] == ','){
            str[i] = ' ';
        }
    }
    stringstream strStream(str);
    int _temp;
    while (strStream >> _temp){
        vct->push_back(_temp);
    }
}

void buildTree(tree *_t, vector<int> _pre, vector<int> _mid){
    int len = (int)_pre.size();
    if(_mid.size() != len){
        cout << "前、中序列不一致" << endl;
        return;
    }
    
    // 递归终止条件
    if(_pre.size() == 2 && _mid.size() == 2) {
        _t->data = _pre[0];
        tree *t = (tree *)malloc(sizeof(tree));
        if(_pre[0] == _mid[0]){
            t->data = _mid[1];
            _t->_right = t;
            _t->_left = nullptr;
        } else {
            t->data = _mid[0];
            _t->_right = nullptr;
            _t->_left = t;
        }
        return;
    }
    
    if(_pre.size()== 1 && _mid.size() == 1){
        _t->data = _pre[0];
        return;
    }
    
    _t->data = _pre[0];
    int pos = 0;
    // 获取位置
    for(int i=0; i<_mid.size(); i++) {
        if(_mid[i] == _pre[0]) {
            pos = i;
            break;
        }
    }
    
    // 构造子树序列
    vector<int> _prel, _prer, _midl ,_midr;
    for(int i=1; i<len; i++){
        if(i<=pos){
            _prel.push_back(_pre[i]);
        } else {
            _prer.push_back(_pre[i]);
        }
    }
    
    for(int i=0; i<len; i++){
        if(i<pos){
            _midl.push_back(_mid[i]);
        } else if(pos < i) {
            _midr.push_back(_mid[i]);
        }
    }
    
    tree *left = (tree *)malloc(sizeof(tree));
    tree *right = (tree *)malloc(sizeof(tree));
    buildTree(left, _prel, _midl);
    _t->_left = left;
    buildTree(right, _prer, _midr);
    _t->_right = right;
}

void postorder(struct tree* t, vector<int> *vct){
    if(t != NULL){
        postorder(t->_left, vct);
        postorder(t->_right, vct);
        vct->push_back(t->data);
    }
}
