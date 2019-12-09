#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float u=2,d=1,temp=0,sum=0;
    int i;
    for(i=1;i<20;i++){
        temp = u;
        u +=d;
        d = temp;
        temp = u/d;
        sum += temp;
        cout<<u<<'/'<<d<<"\t";
        if(i%4 == 0) cout<<endl;
    }
    sum += 2;
    cout<<endl<<"sum="<<setprecision(7)<<sum;
    cout<<endl;
    return 0;
}