//
//  main.cpp
//
//  Created by LiweiGu on 2020/2/26.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 数据结构 队列

typedef int var;

// 循环队列
// 队列结构体
struct Queue{
    var *data;
    int front;
    int rear;
};

// 初始化队列
void init(struct Queue* queue, int size){
    // 开辟数组空间，初始化队列头尾
    queue->data = (var *)malloc(sizeof(var)*size);
    queue->front = 0;
    queue->rear = -1;
}

// 判断空
bool isEmpty(struct Queue* queue){
    // 尾部为-1即为空
    if(queue->rear == -1)
        return true;
    return false;
}

// 判断是否为满队列
bool isFill(struct Queue* queue, int size){
    // 队列为空的两种情况
    // 1. 尾比头大，尾减头+1 满
    // 2. 尾比头小，头减1等于尾
    int f = queue->front;
    int r = queue->rear;
    if((r-f+1 == size) || (0<r<f && r+1 == f))
        return true;
    return false;
}

// 读取队列
void printQueue(struct Queue* queue, int size){
    if(isEmpty(queue))
        return;
    int f = queue->front;
    int r = queue->rear;
    while (f!=r) {
        printf("%d\t", queue->data[f++]);
        if(f == size)
            f = 0;
    }
    printf("%d\t", queue->data[f]);
    printf("\n");
}

// 插入
bool inserQueue(struct Queue* queue, int size ,int data){
    if(isFill(queue, size))
        return false;
    int r = queue->rear + 1;
    if(r == size){
        queue->data[0] = data;
        queue->rear = 0;
    } else if(r < size){
        queue->data[r] = data;
        queue->rear = r;
    }
    return true;
}

// 删除
var deleteQueue(struct Queue* queue, int size){
    var bup = -1;
    if(isEmpty(queue))
        return bup;
    bup = queue->data[queue->front];
    int f = queue->front + 1;
    int r = queue->rear;
    if(f == size)
        f = 0;
    // 判断是否为空
    if(f == r){
        r = -1;
    }
    queue->front = f;
    queue->rear = r;
    return bup;
}


int main(){
    /* testing Queue */
    struct Queue queue;
    // 初始化
    init(&queue, 5);
    // 无反应
    printf("初始化打印: \n");
    if(isEmpty(&queue))
        printf("为空\n");
    printf("头:%d, 尾:%d\n", queue.front, queue.rear);
    printQueue(&queue, 5);
    
    // 插入
    inserQueue(&queue, 5, 1);
    inserQueue(&queue, 5, 2);
    inserQueue(&queue, 5, 3);
    inserQueue(&queue, 5, 4);
    inserQueue(&queue, 5, 5);
    if(isFill(&queue, 5))
        printf("满的\n");
    printf("头:%d, 尾:%d\n", queue.front, queue.rear);
    printQueue(&queue, 5);
    
    deleteQueue(&queue, 5);
    if(!isFill(&queue, 5))
        printf("不满的\n");
    printf("头:%d, 尾:%d\n", queue.front, queue.rear);
    printQueue(&queue, 5);
    
    inserQueue(&queue, 5, 6);
    if(isFill(&queue, 5))
        printf("满的\n");
    printf("头:%d, 尾:%d\n", queue.front, queue.rear);
    printf("插入打印: \n");
    printQueue(&queue, 5);
    
    deleteQueue(&queue, 5);
    deleteQueue(&queue, 5);
    deleteQueue(&queue, 5);
    deleteQueue(&queue, 5);
    deleteQueue(&queue, 5);
    if(isEmpty(&queue))
        printf("为空\n");
    printf("头:%d, 尾:%d\n", queue.front, queue.rear);
    printQueue(&queue, 5);
    
    return 0;
}
