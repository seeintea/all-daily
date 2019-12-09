#include <iostream>
using namespace std;

int main() {

    void arrInput(int *a, int size);
    void arrSort(int *a, int size);
    void arrOutput(int *a, int size);

    int arr[10];
    arrInput(arr,10);
    arrSort(arr,10);
    arrOutput(arr,10);
    return 0;
}

void arrInput(int *a, int size) {
    cout<<"please input int array:";
    for(int i=0;i<size;i++) cin>>*(a+i);
}

void arrSort(int *a, int size) {
    int min = *a, max = *a, temp;
    int minIndex = -1, maxIndex = -1;
    for(int i=0;i<size;i++){
        if(*(a+i)>= max) {
            max = *(a+i);
            maxIndex = i;
        } else if(*(a+i) <= min){
            min = *(a+i);
            minIndex = i;
        }
    }
    temp = *a;
    *a = min;
    *(a+minIndex) = temp;
    temp = *(a+size-1);
    *(a+size-1) = max;
    *(a+maxIndex) = temp;
}

void arrOutput(int *a, int size){
    for(int i=0;i<size;i++) cout<<*(a+i)<<'\t';
    cout<<endl;
}