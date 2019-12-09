#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float x0,x1,a;
    cout<<"please input a number(>0):";
    cin>>a;
    x0 = a/2;
    x1 = (x0+a/x0)/2;
    while (fabs(x1-x0)>1e-5){
        x0 = x1;
        x1 = (x0+a/x0)/2;
        //cout<<"x0,x1 = "<<x0<<'\t'<<x1<<endl;
    }
    cout<<"x1="<<x1<<endl;
    return 0;
}