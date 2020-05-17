//
//  main.cpp
//  dsa_work
//
//  Created by LiweiGu on 2020/5/14.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 实现一个迷宫问题的求解
 要求：
 输入一个n*n的矩阵，以0代表道路，以1代表障碍物，实现一个算法，要求能够给出从入口（默认为左上角）到出口（默认为右下角）的路线。
 
 输入
 第一行一个n。
 第二行开始是一个（n+2）*（n+2）的矩阵（四周边框为1）
 
 输出
 从左上角（1，1）到右下角（n，n）的序列。
 测试用例确保具有通路
 */

// 记录矩阵的位置
typedef struct {
    int x;  // 横坐标
    int y;  // 纵坐标
    int z;  // 记录最后一次检索方位 [0:左, 1:下, 2:右, 3:上]
} pos;

// 检索函数
void matrixSearch(const vector< vector<int> > matrix, vector<pos> *visited);

// 判断是否为同一位置
bool isPos(pos after, pos before);

int main(int argc, const char * argv[]) {
    
    // 获取用户输入矩阵规模
    int _in = 0;
    cout << "请输入矩阵规模:";
    cin >> _in;
    if( _in == 0 ){
        cout << "输入有误！" << endl;
        return 0;
    }
    int _need = _in + 2;
    cout << "请输入规模为" << _need << "的矩阵: " <<endl;
    
    // 初始化矩阵
    vector< vector<int> > matrix(_need, vector<int>(_need));
    // 赋值
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            cin >> _in;
            matrix[i][j] = _in;
        }
    }
    
    // 记录访问路线
    vector<pos> visited;
       
    // 寻找迷宫路径
    // 从 (1,1) 到 (_in, _in) 的路线
    _in = _need - 2;
    // 记录坐标点 (1, 1)
    pos start;
    start.x = 1;
    start.y = 1;
    start.z = 0;
    visited.push_back(start);
    
    // 顺着查找左下右上
    while (start.x != _in || start.y != _in) {
        matrixSearch(matrix, &visited);
        start = visited.back();
    }
    
    cout << "走出迷宫的路径为: " << endl;
    for(vector<pos>::iterator iter = visited.begin(); iter != visited.end(); iter++){
        int _x = iter->x;
        int _y = iter->y;
        cout << "(" << _x << "," << _y << ")" << endl;
    }
    
}

void matrixSearch(const vector< vector<int> > matrix, vector<pos> *visited) {
    // 最新一次访问结果
    pos *_node = &visited->back();
    int _x = _node->x;
    int _y = _node->y;
    
    // 上一次检索失败标志
    if(_node->z == 5) {
        // 删除节点
        visited->pop_back();
        return;
    }
    
  
    pos _new;
    _new.z = 0;
    int _bup = _node->z;
    
    // 获取上一次访问地址
    vector<pos>::iterator iter = visited->end();
    pos _temp;
    if(visited->size() > 1){
        --iter;
        _temp = *--iter;
    } else {
        _temp.x = 0;
        _temp.y = 0;
    }
    
    // 开始侦查
    // 右
    if(matrix[_x][_y+1] == 0 && _bup != 1){
        _node->z = 1;
        _new.x = _x;
        _new.y = _y+1;
        if(isPos(_new, _temp)){
            return;
        }
        visited->push_back(_new);
        return;
    }

    // 下
    if(matrix[_x+1][_y] == 0 && _bup != 2){
        _node->z = 2;
        _new.x = _x+1;
        _new.y = _y;
        if(isPos(_new, _temp)){
            return;
        }
        visited->push_back(_new);
        return;
    }

    // 左
    if(matrix[_x][_y-1] == 0 && _bup != 3){
        _node->z = 3;
        _new.x = _x;
        _new.y = _y-1;
        if(isPos(_new, _temp)){
            return;
        }
        visited->push_back(_new);
        return;
    }

    // 上
    if(matrix[_x-1][_y] == 0 && _bup != 4){
        _node->z = 4;
        _new.x = _x-1;
        _new.y = _y;
        if(isPos(_new, _temp)){
            return;
        }
        visited->push_back(_new);
        return;
    }
    
    // 检索失败
    _node->z = 5;
}

bool isPos(pos after, pos before) {
    if(after.x == before.x && after.y == before.y)
        return true;
    return false;
}
