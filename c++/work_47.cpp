#include <iostream>
using namespace std;

void gotbaha(int x);
bool prime(int x);

int main() {
    int x;
    cout<<"please input number > 6 & even:";
    cin>>x;
    gotbaha(x);
    return 0;
}

void gotbaha(int x){
    int m,n,state = 0;
    for(m=1;m<(x/2);m++){
        if(!prime(m)){
            continue;
        }
        for(n=x;n>(x/2);n--){
            if(!prime(n)){
                continue;
            } else {
                if(x == (m+n)){
                    cout<<x<<"="<<m<<"+"<<n<<endl;
                    state++;
                    break;
                }
            }
        }
        if(state != 0){
            break;
        }
    }
}

bool prime(int x){
    int index_x,index_y;
    int state = 0;
    for(index_x=1;index_x<x;index_x++){
        for(index_y=2;index_y<(index_x/2);index_y++){
            if(x%index_y == 0){
                state++;
            }
            if(state != 0){
                return false;
            }
        }
    }
    return true;
}