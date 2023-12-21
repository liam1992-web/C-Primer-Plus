#include <iostream>
#include <string>
#include <new>

using namespace std;

const int BUF = 512;

class JustTesting
{
    private:
        string words;
        int number;
    public:
        JustTesting(const string & s = "Just Testing", int n = 0)
            {words = s; number = n; cout << words << " constructed\n";}

        ~JustTesting() {cout << words << " destroyed\n";}

        void Show() const { cout << words << ", " << number << endl;}
};

int main()
{
    char * buffer = new char[BUF];

    JustTesting *pc1, *pc2;
    pc1 = new (buffer) JustTesting;         //place object in buffer
    pc2 = new JustTesting("Heap1", 20);     //place object on hep
    cout << "Memory block addresses:\n" << "buffer: " << (void*)buffer << "    heap: " << pc2 << endl;
    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    JustTesting *pc3, *pc4;
    pc3 = new(buffer + sizeof(JustTesting))JustTesting("Bad Idea", 6);        
    pc4 = new JustTesting("Heap2", 10);
    cout << "Memory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();

    delete pc2;     //自动调用指向对象的析构函数
    delete pc4;
    pc3->~JustTesting();        //通过指针显式调用析构函数释放对象
    pc1->~JustTesting();
    delete [] buffer;       //delete释放了buffer数组
    cout << "Done\n";       
    return 0;               //释放对象要先后再前，然后才能释放内存单元！！！
}