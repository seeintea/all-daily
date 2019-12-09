#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int i,j,k,d=0,temp=0,sum=0;
    for(i=2;i<1001;i++){
        for(j=1;j<i-1;j++){
            if((i%j)==0){
                temp = j;
                sum += temp;
            }
        }
        if(i == sum){
            cout<<sum<<", its factors are ";
            for(k=1;k<sum-1;k++){
                if((sum%k)==0){
                    d++;
                    if(d == 1) cout<<k;
                    else cout<<","<<k;
                }
            }
            d = 0;
            cout<<endl;
        }
        sum = 0;
    }
    cout<<endl;
    return 0;
}