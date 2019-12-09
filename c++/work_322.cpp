#include <iostream>
using namespace std;

int main() {
    //about monkey
    //core: nowadays n -> before 2(n+1)
    int index,total=1;
    cout<<10<<" day has "<<total<<" peach"<<endl;
    for(index=9;index>0;index--){
        total = 2*(total+1);
        cout<<index<<" day has "<<total<<" peach"<<endl;
    }
    return 0;
}