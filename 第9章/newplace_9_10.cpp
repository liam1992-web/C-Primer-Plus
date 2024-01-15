// using placement new

#include <iostream>
#include <new>     // for placement new

const int BUF = 512;
const int N = 5;
char buffer[BUF];  // chunk of memory  

int main()
{
    using namespace std;

    double *pd1, *pd2;
    int i;

    cout << "Calling new and placement new:\n";
    pd1 = new double[5];                //使用堆
    pd2 = new (buffer) double[N];       //使用buffer内存区域
    for(i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 20.0 * i;
    cout << "Memory addresses:\n" << " heap: " << pd1       //pd1是double指针，buffer是char指针，所以cout输出时要对buffer进行强制类型转换
         << " static: " << (void *) buffer << endl;         //pd2数组地址和buffer数组地址相同
    cout << "Memory contents:\n";
    for(i = 0; i < N; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;        //使用 定位new运算符 将数组pd2放在数组buffer中
    }   

    cout<< "\nCalling new and placement new a second time:\n";
    double *pd3, *pd4;
    pd3 = new double[N];
    pd4 = new (buffer) double[N];                           //定位new运算符 分配相同的内存块/地址相同；new使用传递给他的地址，不跟踪哪些内存已被使用或哪些未被使用，地址需要程序员来确定
    for(i = 0; i < N; i++)
        pd4[i] = pd3[i] = 1000 + 40.0 * i;
    cout << "Memory contents:\n";
    for(i = 0; i < N; i++)
    {
       cout << pd3[i] << " at " << &pd3[i] << "; ";
       cout << pd4[i] << " at " << &pd4[i] << endl; 
    }

    cout << "\nCalling new and placement new a third time:\n";
    delete [] pd1;      //释放内存块 堆内存         
    pd1 = new double[N];
    pd2 = new (buffer + N * sizeof(double)) double[N];      //程序员确认定位地址
    for(i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 60.0 * i;
    for(i = 0; i < N; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    delete [] pd1;
    delete [] pd3;   //delete可用于指向常规new运算符分配的堆内存；如果buffer是使用常规new运算符创建的，则可以使用常规delete运算符来释放整个内存块
                    //buffer指定的内存是静态内存，不能使用delete来释放
    return 0;
}
