// writing to a file

#include <iostream>
#include <fstream>

int main()
{
    using namespace std;

    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile;                   //创建对象
    outFile.open("carinfo.txt");        //将对象与文件联系起来，通过open

    cout << "Enter the make and modle of automobile: ";
    cin.getline(automobile,50);
    cout << "Enter the mobile year: ";
    cin >> year;
    cout << "Enter the original asking price: ";
    cin >> a_price;
    d_price = 0.913 * a_price;

    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;

    outFile << fixed;                   //outFile可使用cout可使用的任何方法
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;

    outFile.close();            //使用完文件后将其关闭
    
    return 0;

}
