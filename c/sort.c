//
//  main.cpp
//
//  Created by LiweiGu on 2020/2/26.
//  Copyright © 2020 LiweiGu. All rights reserved.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* 排序算法学习
 * author: LiweiGu
 * date: 20200229
 */


// 打印数组
void printArray(int* arr, int lenght){
    int i = 0;
    printf("[");
    for(; i<lenght-1; i++)
        printf("%d,", arr[i]);
    printf("%d]\n", arr[i]);
}

// 插入排序
void insertSort(int* arr, int length){
    // 循环序列
    int i, j;
    for(i=1; i<length; i++){
        int temp = arr[i];
        // j>0 && arr[j-1]>temp 短路判断
        for(j=i; j>0 && arr[j-1]>temp; j--){
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

// 冒泡排序
void bubbleSort(int* arr, int lenght){
    int i, j, temp;
    for(i=0; i<lenght; i++){
        for(j=i+1; j<lenght; j++){
            if(arr[j]<arr[i]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

// 冒泡排序改进
void bubbleSort_A(int* arr, int lenght){
    // 默认未排序
    bool sweep = false;
    while(!sweep){
        // 已经排序
        sweep = true;
        for(int i=1; i<lenght; i++){
            if(arr[i-1]>arr[i]){
                int temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
                // 修改数组后判定未排序
                sweep = false;
            }
        }
        lenght--;
    }
}

// 归并排序
// 2. 合并
void merge(int arr[], int lo, int mid, int hi){
    // 创建数组接受分治后的数据
    int capL = mid-lo+1;
    int capR = hi-mid;
    // 动态开辟数组
    int* arrL = (int*)malloc(sizeof(int)*capL);
    int* arrR = (int*)malloc(sizeof(int)*capR);
    int i=0,j=lo;
    // 复制前段数组
    for(i=0;i<capL;i++)
        arrL[i] = arr[j++];
    // 复制后段数组
    for(i=0;i<capR;i++)
        arrR[i] = arr[j++];
    // 合并数组
    int m=0, n=0;
    while(m<capL && n<capR){
        if(arrL[m]<=arrR[n])
            arr[lo++] = arrL[m++];
        else
            arr[lo++] = arrR[n++];
    }
    while(m<capL)
        arr[lo++] = arrL[m++];
    while(n<capR)
        arr[lo++] = arrR[n++];
    // 释放空间
    free(arrL);
    free(arrR);
}
// 1. 分治
void mergeSort(int arr[], int lo, int hi){
    if(lo<hi){
        int mid = lo + (hi-lo)/2;
        mergeSort(arr, lo, mid);
        mergeSort(arr, mid+1, hi);
        // 合并
        merge(arr, lo, mid, hi);
    }
}


int main(int argc, const char * argv[]){
    int arr[] = {7,3,1,4,5,6,7,9,3};
    printArray(arr, 9);
    //mergeSort(arr, 0, 8);
    //insertSort(arr, 9);
    //bubbleSort(arr, 9);
    //bubbleSort_A(arr, 9);
    printArray(arr, 9);
    return 0;
}
