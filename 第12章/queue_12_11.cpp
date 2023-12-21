#include "queue_12_10.h"
#include <cstdlib>

Queue::Queue(int qs) :qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

/*从概念上说，调用构造函数时，对象将在括号中的代码执行之前被创建
因此，调用Queue(int qs)构造函数将导致程序首先给4个成员变量分配内存
然后，程序流程进入括号中，使用常规的赋值方式将值存储到内存中
因此，对于const数据成员，必须在执行到构造函数体之前，即创建对象时进行初始化
*/

Queue::~Queue()
{
    Node* temp;
    while(front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

bool Queue::enqueue(const Item & item)
{
    if(isfull())
        return false;
    Node* add = new Node;
    add->item = item;
    add->next = NULL;
    items++;
    if(front == NULL)
        front = add;    //空时，指向新增结点
    else
        rear->next = add;       //非空时，将原最后结点的next指针指向add结点
    rear = add;         //修改对象中的rear指针，使其指向最后一个结点
    return true;
}

bool Queue::dequeue(Item & item)
{
    if(front == NULL)
        return false;
    item = front->item;
    items--;
    Node* temp = front;
    front = front->next;
    delete temp;        //删除节点
    if(items == 0)
        rear = NULL;
    return true;
}

void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}