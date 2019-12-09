/*
@author：GLW.BBN
@time: 2019/10/15/20:44
*/
#include <iostream>
#include <fstream>  //文件读取
#include <sstream>  //读取文件后数据处理
#include <string>   //string类型引入
#include <sstream>  //输入输出控制
using namespace std;

int main() {
    //存放每一行数据
    string lineContent;
    // 循环用索引
    int indexLine = 0, indexColumn;
    // 去除第一行 string 类型内容
    int head = 0;
    // 存放读取文件流数据
    float data[200][20] = {0};
    // 读取*.txt文件
    // 以读模式打开文件
    ifstream infile;
    // ios::in 打开文件用于读取
    infile.open("info.txt",ios::in);
    // 读取报错处理
    if(!infile){
        cout<<"can't open file"<<endl;
        return -1;
    }
    // getline() 读取一行内容 
    while(getline(infile,lineContent)){
        //将 lineContent 内容按空格划分
        istringstream ist(lineContent);
        // 去除第一行 string 类型内容
        if(head == 0){
            head++;
            continue;
        }
        for(indexColumn=0;indexColumn<20;indexColumn++){
            // 格式化后的内容存入数组中 
            ist>>data[indexLine][indexColumn];
        }
        indexLine++;
    }
    // 关闭读取流
    infile.close();
    // 读取文件写入数组操作结束

    // 求某一同学的平均成绩
    // 用户手动输入平均成绩
    int std;
    // 遍历索引
    int indexStd,indexResults;
    // 平均值
    float stdResultsAvg;
    // 多次查询
    char searchState;
    bool searchAgain;
    do{
        cout<<"please input student's id:";
        cin>>std;
        for(indexStd=0;indexStd<std+1;indexStd++){
            if(data[indexStd][0] == std){
                for(indexResults=2;indexResults<20;indexResults++){
                    if(data[indexStd][indexResults] == '\0') break;
                    stdResultsAvg += data[indexStd][indexResults];
                }
            }
        }
        stdResultsAvg = stdResultsAvg/(indexResults-2);
        // 打印出查询学生的平均成绩
        cout<<"std="<<std<<" avg=:"<<stdResultsAvg<<endl;
        cout<<"search again(Y/y or N/n):";
        cin>>searchState;
        if(searchState == 'Y') searchAgain = true;
        else searchAgain = false;
    }while (searchAgain);
    // 求某位学生的平均成绩结束

    // 求班级所有学生平均成绩 并写入文件
    // 循环求平均成绩
    int indexOutColumn, indexOutRow;
    // 平均值
    float OutAverage;
    // 以写模式打开文件
    ofstream outfile;
    // ios::app 追加写入
    // ios::out 打开文件用于写入
    outfile.open("info.txt",ios::app| ios::out);
    // 写模式报错
    if(!outfile){
        cout<<"can not write";
        return -1;
    }
    // 写入数据
    cout<<"数据写入中..."<<endl;
    outfile<<endl;
    outfile << "学号\t" << "班级\t" << "平均分" << endl;
    // 平均值写入
    for(indexOutRow=0;indexOutRow<200;indexOutRow++){
        // 读取空值退出
        if(data[indexOutRow][0] == '\0') break;
        for(indexOutColumn=2;indexOutColumn<20;indexOutColumn++){
            if(data[indexOutRow][indexOutColumn] == '\0') break;
            OutAverage += data[indexOutRow][indexOutColumn];
        }
        // 写入数据
         OutAverage = OutAverage/(indexOutColumn-2);
        outfile <<data[indexOutRow][0]<<'\t'<<data[indexOutRow][1]<<'\t'<<OutAverage<<endl;
    }
    // 关闭写入流
    outfile.close();
    cout<<"数据写入完成！"<<endl;
    return 0; 
}