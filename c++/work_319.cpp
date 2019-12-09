#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int i, h,t,o,temp;
    for(i=100;i<=999;i++){
        h=i/100;
        t=i%100/10;
        o=i%100%10;
        temp = (int)(pow(h,3)+pow(t,3)+pow(o,3));
        if(temp == i){
            cout<<setw(5)<<i;
        }
    }
    cout<<endl;
    return 0;
}