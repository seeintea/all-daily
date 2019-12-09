#include <iostream>
using namespace std;

int fac(int x);

int main() {

    int x,y,z;
    int num = 0;
    cout<<"please input three numbers (int):";
    cin>>x>>y>>z;
    num = fac(x) + fac(y) + fac(z);
    cout<<x<<"! + "<<y<<"! + "<<z<<"! = "<<num<<endl;
    return 0;
}

int fac(int x){
    if(x==1){
        return 1;
    }
    return x*fac(x-1);
}