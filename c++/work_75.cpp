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
    float averageScore = (std.score[0]+std.score[1]+std.score[2])/3.0;
    cout<<"stu.score[average]: "<<averageScore<<endl;
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
    int hightGradeIndex = -1;
    float temp, tempTemp = 0;
    StudentGrade std[10];
    // achieve info
    for(int i=0; i<10; i++){
        std[0] = InputStudentInfo();
    }
    // print info
    for(int i=0; i<10; i++){
        PrintStudentInfo(std[i]);
    }
    // search max
    for(int i=0; i<10; i++){
        temp = (std[i].score[0]+std[i].score[1]+std[i].score[2])/3.0;
        if(temp > tempTemp) {
            tempTemp = temp;
            hightGradeIndex = i;
        }
    }
    // input hightAverge Student
    cout<<"hight Student:"<<std[hightGradeIndex].num<<std[hightGradeIndex].name<<tempTemp<<endl;

    return 0;
}