//
//  main.cpp
//
//  Created by LiweiGu on 2020/2/26.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// KMP 字符串匹配 返回匹配到的位置
int KMP(char* pst, char* text);
// KMP GetNext 匹配前缀
void getNext(char* str, int* next, int len);
// 计算自负数组的长度
int lenght(char* str);

int main(){
    char pst[] = "ababa";
    char text[] = "ababbbabababa";
    printf("%d\n", KMP(pst, text));
    return 0;
}

int KMP(char* pst, char* text){
    // 求字符串长度
    int p = lenght(pst);
    int t = lenght(text);
    // 初始化匹配表
    int* next = (int*)malloc(sizeof(int)*p);
    // 求匹配表
    getNext(pst, next, p);
    // 匹配字符串
    int i = 0;
    int j = 0;
    while(i<p && j<t){
        if(j==-1 || pst[i]==text[j]){
            i++;
            j++;
        } else {
            i = next[i];
        }
    }
    
    // 释放资源
    free(next);
    if(i==p)
        return j-i;
    return -1;
}

void getNext(char* str, int* next, int len){
    next[0] = -1;
    int i = 0;
    int j = -1;
    while (i<len) {
        if(j==-1 || str[i]==str[j]){
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int lenght(char* str){
    int len = 0;
    while(*str++)
        len++;
    return len;
}
