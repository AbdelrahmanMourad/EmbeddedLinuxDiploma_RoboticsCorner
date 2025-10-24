#ifndef __STACK_H__
#define __STACK_H__

class Stack
{

public:
    Stack(int cap);
    bool isEmpty() const;
    bool isFull() const;
    bool push(int element);
    bool pop(int &element);

private:
    int *buffer;
    int top;
    int size;
};

#endif // __STACK_H__
