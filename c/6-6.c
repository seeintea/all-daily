//
//  main.cpp
//
//  Created by LiweiGu on 2020/2/26.
//  Copyright © 2020 LiweiGu. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum( List L );

int main()
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for ( i=0; i<N; i++ ) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}

int tempFunc(int x){
    if(x==1) return 1;
    return x*tempFunc(x-1);
}

int FactorialSum (List L){
    // 无任何数值
    if(!L) return 0;
    // 计算链表的长度
    int temp = L->Data;
    int indeNum = tempFunc(temp);
    int sum = indeNum;
    int sub = 0;
    L = L->Next;
    
    while (L) {
        int arr = L->Data;
        if(temp<arr){
            sub = arr - temp;
            temp = arr;
            while(sub){
                indeNum = (temp--)*indeNum;
                sub--;
            }
            sum += indeNum;
        } else if(temp>arr){
            sub = temp - arr;
            while (sub) {
                indeNum = indeNum/(temp--);
                sub--;
            }
            sum += indeNum;
        } else{
            sum += sum;
        }
        temp = arr;
        L = L->Next;
    }
    return sum;
}
