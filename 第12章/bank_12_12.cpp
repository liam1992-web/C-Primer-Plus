#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue_12_10.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    //初始化  
    std::srand(std::time(0));

    cout << "Case Study:Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;   //循环次数

    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;        //两个顾客之间的间隔时间

    Item temp;          //新顾客对象
    long turnaways = 0;     //排满而拒之门外
    long customers = 0;     //排队等待顾客人数
    long served = 0;        //服务，工作时间
    long sum_line = 0;      //累计队列长度
    int wait_time = 0;      //直到自动取款机空闲的时间
    long line_wait = 0;     //累计排队时间

    //运行模拟程序
    for(int cycle = 0; cycle < cyclelimit; cycle++) //整体循环
    {
        if(newcustomer(min_per_cust))   //产生新顾客
        {
            if(line.isfull())
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);    //办理业务时间，到达队伍的时间
                line.enqueue(temp); //顾客进入队列
            }
        }

        if(wait_time <= 0 && !line.isempty())
        {
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if(wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();
    }

    //打印数据
    if(customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait time: " << (double) line_wait / served << " mintues\n";
    }
    else 
        cout << "No customers!\n";
    
    cout << "Done!\n";

    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}