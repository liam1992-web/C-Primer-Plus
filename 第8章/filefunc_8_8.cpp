// function with ostream & parameter

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void file_it(ostream & os, double fo, const double fe[], int n);

const int LIMIT = 5;

int main()
{
    ofstream fout;      //对象
    const char * fn = "ep-data.txt";

    fout.open(fn);      //打开文件
    if(!fout.is_open())
    {
        cout << "Can't open " << fn << ". Bye.\n";
        exit(EXIT_FAILURE);
    }

    double objective;
    cout << "Enter the focal length of your "
            "telescope objective in mm: ";
    cin >> objective;

    double eps[LIMIT];
    cout << "Enter the focal lengths, in mm, of " << LIMIT
         << " eyepieces:\n";
    for(int i = 0; i < LIMIT; i++)
    {
        cout << "Eyepiece #" << i + 1 << ": ";
        cin >> eps[i];
    }

    //函数参数类型为 ostream & ，可以接受 ostream对象（如cout），也可以接受 ofstream对象（如fout）
    file_it(fout, objective, eps, LIMIT);       //写入到文件中
    file_it(cout, objective, eps, LIMIT);       //写到终端
    cout << "Done\n";

    return 0;
}

void file_it(ostream & os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;
     //使用ostream类中的格式化方法
    initial = os.setf(ios_base::fixed);    //方法调用 setf(ios_base::fixed) 将对象置于使用定点表示法的模式 save initial formatting state
    os.precision(0);                       //方法precision指定显示多少位小数（假定对象处于定点模式下）
    os << "Focal length of objective: " << fo << " mm\n";
    os.setf(ios::showpoint);            //setf(ios::showpoint)将对象置于显示小数点的模式，即使小数部分为零
    os.precision(1);                    //方法precision指定显示多少位小数（假定对象处于定点模式下）
                                        //这些设置都将一直保持不变，直到再次调用相应的方法重新设置它们
    os.width(12);                       //方法width()设置下一次输出操作使用的字段宽度，这种设置只在显示下一个值时有效，然后将恢复到默认设置。默认的字段宽度为零
    os << "f.1. eyepiece";
    os.width(15);
    os << "magnification" << endl;
    for(int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int (fo/fe[i] + 0.5) << endl;
    }
    os.setf(initial);			// restore initial formatting state
}

/*
    方法setf()返回调用它之前有效的所有格式化设置
    ios_base::fmtflags是存储这种信息所需的数据类型名称
    将返回赋给 initial 将存储调用file_it()之前的格式化设置，然后便可以使用变量 initial作为参数来调用 setf()，将所有的格式化设置恢复到原来的值。
    因此，该函数将对象回到传递给file_it()之前的状态。
*/
