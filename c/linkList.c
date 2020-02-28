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
struct Node* createNode(var data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// 顺序插入
// 返回节点插入的位置
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
// 返回被替换的节点的值
var insert(struct Node* node, var data, int index){
    // 查询位置是否符合要求
    if(!index) return (var)-1;
    int count = 0;
    struct Node* rear = node->next;
    while (rear && count < index-2) {
        rear = rear->next;
        count++;
    }
    if(!rear)
        return (var)-1;
    var bup = rear->data;
    rear->data = data;
    return bup;
}

// 移除某个节点
// 返回被移除的节点的值
var remove(struct Node* node, int index){
    // 查询位置是否符合要求
    if(!index) return (var)-1;
    int count = 0;
    struct Node* rear = node->next;
    while (rear && count < index-1) {
        rear = rear->next;
        count++;
    }
    var bup = rear->data;
    printf("|%d|\n", bup);
    // 创建临时节点
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    // 绑定要删除的节点
    temp = rear;
    // 下一节点不为空
    if(rear->next){
        printf("-%d-\n", rear->next->data);
        rear = rear->next;
    }
    free(temp->next);
    return bup;
}

// 打印所有的节点
void printNode(const struct Node* node){
    struct Node* rear = node->next;
    while (rear) {
        printf("%d\t", rear->data);
        rear = rear->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]){
    struct Node* list = (struct Node*)malloc(sizeof(struct Node));
    init(list);
    printf("%d\n", append(list, 12));
    printf("%d\n", append(list, 14));
    printf("%d\n", append(list, 18));
    printf("%d\n", append(list, 20));
    printf("%d\n", append(list, 22));
    printNode(list);
    printf("%d\n", insert(list, 10, 1));
    printf("%d\n", insert(list, 11, 2));
    printf("%d\n", insert(list, 12, 3));
    printf("%d\n", insert(list, 13, 4));
    printf("%d\n", insert(list, 13, 7));
    printf("%d\n", insert(list, 14, 5));
    printf("%d\n", insert(list, 13, 9));
    printNode(list);
    remove(list, 2);
    printNode(list);
}
