//
//  main.cpp
//
//  Created by LiweiGu on 2020/2/26.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 堆栈实现
typedef int var;

struct inn {
    // 数组实现
    var* data;
    int bot;
    int top;
    int _size;
};

// 打印测试
void printInn(struct inn* inn, int topIndex){
    for(int i=0; i<=topIndex; i++)
        printf("%d\t", inn->data[i]);
    printf("\n");
}

// 初始化
void init(struct inn* inn, int size){
    inn->data = (var*)malloc(sizeof(var)*size);
    inn->top = -1;
    inn->bot = 0;
    inn->_size = size;
}


// 检测空栈
bool isEmpty(struct inn* inn){
    if(inn->top == -1)
        return true;
    return false;
}

// 入栈
bool push(struct inn* inn, var data){
    if(++(inn->top) < inn->_size){
        inn->data[inn->top] = data;
        return true;
    }
    // 对先前的加取消
    (inn->top)--;
    return false;
}

// 出栈
bool pop(struct inn* inn){
    if(isEmpty(inn))
        return false;
    if(--(inn->top) < 0)
        inn->top = -1;
    return true;
}

// 读取栈顶
int top(struct inn* inn){
    printf("top: %d\n", inn->data[inn->top]);
    return inn->top;
}


int main(){
    struct inn inn;
    init(&inn, 5);
    bool res = isEmpty(&inn);
    if(res)
        printf("栈空\n");
    res = pop(&inn);
    if(!res)
        printf("pop fail\n");
    res = push(&inn, 2);
    res = push(&inn, 3);
    printInn(&inn, top(&inn));
    res = push(&inn, 4);
    res = push(&inn, 5);
    if(res)
        printf("push suc\n");
    res = push(&inn, 6);
    pop(&inn);
    res = push(&inn, 7);
    if(!res)
        printf("push fail\n");
    printf("%d\n", top(&inn));
    printInn(&inn, top(&inn));
    return 0;
}
