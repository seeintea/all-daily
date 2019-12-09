#include <iostream>
#include <stddef.h>
using namespace std;

int main() {
    int a[10] = {2,3,5,7,9};
    int needNum;
    int i,j,temp;
    int aSize = sizeof(a)/sizeof(int)-1;
    cout<<"please input a number:";
    cin>>needNum;
    for(i=0;i<10;i++){
        if(needNum <= a[i] || a[i] == 0){
            break;
        }
    }
    for(j=aSize-1;j>=i;j--){
        a[j+1] = a[j];
    }
    a[j+1] = needNum;
    for(int k=0;k<aSize;k++){
        cout<<a[k]<<"\t";
    }
    cout<<endl;
    return 0;
}