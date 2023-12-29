// following number input with line input

#include <iostream>
int main()
{
    using namespace std;
    cout << "What year was your house built?\n";
    int year;
    cin >> year;  //(cin >> year).get(); (cin >> year).get(ch); 
    cin.get(); //cin.get(ch); cin读取年份，将回车键生成的换行符留在输入队列中，在下一个cin输入时，看到换行符认为是空行
    cout << "What is its street address?\n";
    char address[80];
    cin.getline(address,80);
    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";
    return 0;
}
