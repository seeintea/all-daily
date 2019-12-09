#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int arr[10][10] = {0};
    // frontier == 1
    for(int i=0;i<10;i++){
        arr[i][0] = 1;
        for(int j=0;j<10;j++){
            if(i==j) arr[i][j] = 1;
        }
    }

    // YH angular
    for(int i=2;i<10;i++){
        for(int j=0;j<10;j++){
            if(arr[i][j] == 1) continue;
            else {
                arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
            }
        }
    }

    // formation print 
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<setw(6)<<arr[i][j];
        }
        cout<<endl;
    }


    return 0;
}