#include <iostream>
#include <string>
using namespace std;

// student`s info and score struct
struct StudentGrade {
    int num;
    char name[32];
    float score[3];
};

void PrintStudentInfo(StudentGrade std){
    cout<<"stu.num: "<<std.num<<endl;
    cout<<"stu.name: "<<std.name<<endl;
    cout<<"stu.score: "<<std.score[0]<<", "<<std.score[1]<<", "<<std.score[2]<<endl;
}

StudentGrade InputStudentInfo(){
    StudentGrade std;
    cout<<"please input num:";
    cin>>std.name;
    cout<<"please input name:";
    cin>>std.name;
    cout<<"please input score:";
    for(int i=0; i<3; i++){
        cin>>std.score[i];
    }
    return std;
}

int main() {
    StudentGrade std = InputStudentInfo();
    PrintStudentInfo(std);
    return 0;
}