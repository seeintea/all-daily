#include <iostream>
using namespace std;

int main() {
    int temp,state;
    int aIndex[3];  //save max index
    int arr[3][4] = {1,5,3,4,
                     5,6,7,8,9,
                     10,11,12};

    // achieve max in arr[j][?]
    for(int j=0;j<3;j++){
        temp = -1;
        for(int i=0; i<4; i++){
            if(arr[j][i]>temp){
                temp = arr[0][i];
                aIndex[j] = i;
            }
        }
    }

    // achieve max in arr[?][j]
    for(int i=0;i<3;i++){
        state = 0;
        temp = arr[i][aIndex[i]];
        for(int j=0;j<3;j++){
            if(temp > arr[j][aIndex[i]]) break;
            state ++;
            if(state == 3){
                cout<<temp<<endl;
            }
        }
    }

    

    return 0;
}