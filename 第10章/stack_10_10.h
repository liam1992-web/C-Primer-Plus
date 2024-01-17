// class definition for the stack ADT

#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
    private:
        enum {MAX = 10};	// constant specific to class
        Item items[MAX];	// holds stack items
        int top;		// index for top stack item
    public:
        Stack();
        bool isempty() const;
        bool isfull() const;
        bool push(const Item & item);	// push() returns false if stack already is full, true otherwise
        bool pop(Item & item);		// pop() returns false if stack already is empty, true otherwise
					// pop top into item
};

#endif
