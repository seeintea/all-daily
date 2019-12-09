#include <iostream>
using namespace std;

int main() {
    int strcmp(char *p1, char *p2);

    char a[] = "abcd";
    char b[] = "Abcd";
    char c[] = "abcd";
    cout<<strcmp(a,b)<<endl;
    cout<<strcmp(b,a)<<endl;
    cout<<strcmp(a,c)<<endl;
    return 0;
}

int strcmp(char *p1, char *p2) {
    while (*p1 == *p2){
        p1++;
        p2++;
        if((*p1 == '\0') && (*p2 == '\0')) {
            return 0;
        } 
    }
    if(*p1 > *p2) return 1;
    else return -1;
}