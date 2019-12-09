#include <iostream>
#include <stddef.h>
using namespace std;

void arrageArr(int arr[],int size);

int main() {
    int temp;
    int a[] = {1,2,3,4,5};
    int b[] = {1,2,3,4,5,6};
    int aSize = sizeof(a)/sizeof(int);
    int bSize = sizeof(b)/sizeof(int);
    arrageArr(a,aSize);
    arrageArr(b,bSize);
    return 0;
}

void arrageArr(int arr[],int size) {
    int sizeState = size-1;
    int temp;
    for(int i=0;i<size/2;i++,sizeState--){
        temp = arr[i];
        arr[i] = arr[sizeState];
        arr[sizeState] = temp;
    }
    for(int k=0;k<size;k++){
        cout<<arr[k]<<"\t";
    }
    cout<<endl;
}