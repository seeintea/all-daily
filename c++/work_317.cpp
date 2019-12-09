#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a,n,sum=0,index,temp=0;
    cout<<"please input a,n:(0<a<9):";
    cin>>a>>n;
    if(a>10 || a<0){
        cout<<"input worry"<<endl;
        return 0;
    }
    for(index=0;index<n;index++){
        temp = a*(int)pow(10,index)+temp;
        if(index == (n-1)){
            cout<<temp<<"=";
        }else {
            cout<<temp<<"+";
        }
        sum += temp;
    }
    cout<<sum<<endl;

    return 0;
}