//
//  main.cpp
//
//  Created by LiweiGu on 2020/2/26.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

#include <stdio.h>

typedef int var;

// utils
void printArray(var* arr, int size){
    for(int i=0; i<size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int division(var* arr, int lo, int hi){
    int pivot = lo;
    int index = pivot+1;
    for(int i=index; i<=hi; i++){
        if(arr[i]<arr[pivot]){
            swap(&arr[i], &arr[index]);
            index++;
        }
    }
    swap(&arr[pivot], &arr[index-1]);
    return index-1;
}

// QuickSort
void quickSort(var* arr, int lo, int hi){
    if(lo < hi){
        int div = division(arr, lo, hi);
        quickSort(arr, lo, div-1);
        quickSort(arr, div+1, hi);
    }
}

int main(){
    var arr[10] = {6, 4, 5, 3, 5, 3, 2, 1, 9, 7};
    printArray(arr, 10);
    quickSort(arr, 0, 9);
    printArray(arr, 10);
    return 0;
}
