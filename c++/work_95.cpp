#include <iostream>
using namespace std;

// define class include std_id and std_score
class Student {
private:
    int stdList[5][2];
public:
    Student() {
        cout<<"using default constructor ."<<endl;
    }
    ~Student() {
        cout<<"using default release func ."<<endl;
    }
    void setStdList();
    void getHightInStdList(Student *p);
};

void Student::setStdList(){
    int i,j;
    for(i=0;i<5;i++){
        cout<<"please input "<<i<<" std's id and score: ";
        for(j=0;j<2;j++){
            cin>>stdList[i][j];
        }
    }
}

void Student::getHightInStdList(Student *p){
    int max=0, temp, index;
    for(int i=0; i<5; i++){
        temp = p->stdList[i][1];
        if(temp > max){
            max = temp;
            index = i;
        }
    }
    cout<<"max score student's stuID: "<<p->stdList[index][0]<<" score: "<<p->stdList[index][1]<<endl;
}

int main(){
    Student std;
    Student *pStd = &std;
    pStd -> setStdList();
    pStd -> getHightInStdList(pStd);
    return 0;
}