#include <iostream>
#include <string>
using namespace std;

int main() {
    void my_stract(char str1[],char str2[]);
    void my_strcmp(char str1[],char str2[]);
    char str1[] = "China";
    char str2[] = "I Love China";
    char str3[] = "China";
    my_stract(str1,str2);
    my_strcmp(str1,str2);
    my_strcmp(str2,str1);
    my_strcmp(str1,str3);
    return 0;
}

void my_strcmp(char str1[],char str2[]){
    int x = strlen(str1);
    int y = strlen(str2);
    if(x > y) {
        cout<<(x-y)<<endl;
    } else if (x < y) {
        cout<<(x-y)<<endl;
    } else {
        int i;
        for(i=0; i<x; i++) {
            if(str1[i] != str2[i]){
                cout<<"x=y str1 != str2"<<endl;
                break;
            }
        }
        if(i == x){
            cout<<"0"<<endl;
        }
    }
}


void my_stract(char str1[],char str2[]) {
    int x = strlen(str1);
    int y = strlen(str2);
    char arr[x+y+10];
    for(int i=0; i<x; i++){
        arr[i] = str1[i];
    }
    arr[x] = ' ';
    x = x+1;

    for(int j=0; j<y; j++){
        arr[x+j] = str2[j];
    }

    cout<<arr<<endl;
}

