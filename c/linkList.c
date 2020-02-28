//
//  main.cpp
//
//  Created by LiweiGu on 2020/2/26.
//  Copyright © 2020 LiweiGu. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

/*
 说明: 链表的头节点为空节点，不作为可操作节点使用
      同样头节点不纳入节点的长度
 */

typedef int var;

// 链表结构体
struct Node {
    var data;
    struct Node* next;
};

// 链表初始化
void init(struct Node* node){
    node->next = NULL;
}

// 创建新节点
// 返回新节点指针
// test pass
struct Node* createNode(var data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// 顺序插入
// 返回节点插入的位置
// test pass
int append(struct Node* node, var data){
    struct Node* newNode = createNode(data);
    int count = 1;
    while (node->next) {
        node = node->next;
        count++;
    }
    node->next = newNode;
    return count;
}

// 制定位置插入
// not pass
bool insert(struct Node* node, var data, int index){
    // 判断索引是否负越界
    if(index <= 0) return false;
    // 寻找插入位置并判断是否负越界
    struct Node* rear = node->next;
    int count = 1;
    while(rear && count++ < index-1)
        rear = rear->next;
    // 如果 rear 为空，则正越界
    if(!rear)
        return false;
    // 如果 index == 1，插入节点为头节点
    if(index == 1){
        // 创建需要插入的节点
        struct Node* newNode = createNode(data);
        newNode->next = node->next;
        node->next = newNode;
        return true;
    }
    // 正常插入节点
    // 考虑细节 -> 节点是否有后继节点
    struct Node* temp = rear->next;
    // 无后继节点
    if(!temp){
        temp = createNode(data);
        rear->next = temp;
        return true;
    }
    temp = createNode(data);
    temp->next = rear->next;
    rear->next = temp;
    return true;
}

// 移除某个节点
// 返回被移除的节点的值
// test pass
var remove(struct Node* node, int index){
    var bup = -1;
    // 判断索引是否负越界
    if(index <= 0) return bup;
    // 判断索引是否正越界
    struct Node* rear = node->next;
    int count = 1;
    // 跳出循环的条件
    // 当前节点为空 -> 正越界
    // count <= index index在符合添加的范围内[ 1 - _size ]
    // 移除节点需要找到被移除节点的前置节点
    while(rear && count++ < index-1)
        rear = rear->next;
    // 如果 rear 为空，则正越界
    if(!rear)
        return bup;
    // 如果 index == 1，头节点指向下一位
    if(index == 1){
        // 释放内存并将链表的元素头指针移位
        struct Node temp;
        temp.next = node->next;
        node->next = rear->next;
        bup = temp.next->data;
        free(temp.next);
        return bup;
    }
    // 正常删除节点
    struct Node temp;
    temp.next = rear->next;
    rear->next = rear->next->next;
    bup = temp.next->data;
    free(temp.next);
    return bup;
}

// 打印所有的节点
// test pass
void printNode(const struct Node* node){
    struct Node* rear = node->next;
    while (rear) {
        printf("%d\t", rear->data);
        rear = rear->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]){
    /* testing */
    struct Node* list = (struct Node*)malloc(sizeof(struct Node));
    init(list);
    printf("%d\n", append(list, 12));
    printf("%d\n", append(list, 14));
    printf("%d\n", append(list, 18));
    printf("%d\n", append(list, 20));
    printf("%d\n", append(list, 22));
    printNode(list);
    printf("%d\n", remove(list, 1));
    printf("%d\n", remove(list, 4));
    printf("%d\n", remove(list, 5));
    printNode(list);
    printf("%d\n", insert(list, 12, 4));
    printf("%d\n", insert(list, 22, 1));
    printf("%d\n", insert(list, 26, 7));
    printNode(list);
    /* testing */
}
