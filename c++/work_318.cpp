#include <iostream>
using namespace std;

#define N 20

int main() {
    //sum = 1!+2!+...+20! 
    long int index,sum,temp = 1;
    for(index=1;index<=N;index++){
        temp = index*temp;
        cout<<temp<<endl;
        sum += temp;
    }
    cout<<endl<<"sum="<<sum<<endl;
    return 0;
}