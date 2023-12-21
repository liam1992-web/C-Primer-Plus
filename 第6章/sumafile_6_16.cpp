//文件输出

#include <iostream>
#include <fstream>
#include <cstdlib>

const int SIZE = 60;

int main()
{
    using namespace std;
    char filename[SIZE];
    ifstream inFile;

    cout << "Enter name of data file: ";
    cin.getline(filename,SIZE);         //用户输入文件名并存储在数组中
    inFile.open(filename);

    if(!inFile.is_open())           //检查文件是否正确打开
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }

    double value;
    double sum = 0.0;
    int count = 0;

    inFile >> value;
    while(inFile.good())        //指出最后一次读取输入的操作是否成功
    {
        ++count;
        sum += value;
        inFile >> value;
    }
//L30,L31,L35可调整为


    if(inFile.eof())        //程序读取文件时不应超过EOF
        cout << "End of file reached.\n";
    else if(inFile.fail())      //类型不匹配
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unkown reason.\n";
    
    if(count == 0)
        cout << "No data processed.\n";
    else
    {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }

    inFile.close();
    return 0;
}