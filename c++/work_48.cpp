#include <iostream>
using namespace std;

float p(float n,float x);

int main() {
    float x,y,put;    
    cout<<"pleas input tow numbers:";
    cin>>x>>y;
    put = p(x,y);
    cout<<put<<endl;
    return 0;
}

float p(float n,float x) {
    if(n==0){
        return 1;
    } else if(n==1){
        return x;
    } else if(n>1){
        return ((2*n-1)*x-p(n-1,x)-(n-1)*p(n-2,x))/n;
    }
}