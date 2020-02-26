//
//  main.cpp
//
//  Created by LiweiGu on 2020/2/26.
//  Copyright © 2020 LiweiGu. All rights reserved.
//
#include <stdio.h>

#define MAX 10  // 定义顺序表的初始容量

// 顺序表结构体
template <typename T>
struct List{
    T data[MAX];
    int length;
};

// 初始化顺序表
template <typename T> void init(struct List<T>* p){
    p->length = 0;
}

// 插入元素 true-插入成功
template <typename T> bool insertEle(struct List<T>* p, T data){
    if(p->length >= MAX) return false;  // 后期扩容操作
    p->data[p->length++] = data;
    return true;
}

// 替换元素
template <typename T> T replaceEle(struct List<T>* p, int index, T data){
    if(index < 0 || index >= MAX || index >= p->length ) return -1;  // 越界｜越界｜非替换元素
    T bup = p->data[index]; // 备份元素
    p->data[index] = data;
    return bup;
}

// 删除元素
template <typename T> T removeEle(struct List<T>* p, int index){
    if(index < 0 || index >= MAX || index >= p->length ) return -1;  // 越界｜越界｜非替换元素
    T bup = p->data[index];
    // 遍历数组
    for(; index < p->length; index++)
        p->data[index] = p->data[index+1];
    p->length--;
    return bup;
}

// 打印顺序表
template <typename T> void printList(const struct List<T>* p){
    for(int i=0; i<p->length-1; i++)
        printf("%d,", p->data[i]);
    printf("%d\n", p->data[p->length-1]);
}

int main(int argc, const char * argv[]){
    struct List<int> list;
    init<int>(&list);
    
    insertEle(&list, 1);
    insertEle(&list, 2);
    insertEle(&list, 3);
    
    printList(&list);
    
    printf("%d\n",replaceEle(&list, 2, 7));
    printf("%d\n",replaceEle(&list, 3, 7));
    
    printList(&list);
    
    insertEle(&list, 4);
    
    printf("%d\n",removeEle(&list, 3));
    printf("%d\n",removeEle(&list, 5));
    
    printList(&list);
}
