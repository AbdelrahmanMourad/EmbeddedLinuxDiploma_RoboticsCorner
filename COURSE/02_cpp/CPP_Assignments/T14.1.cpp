
/*
========================================================================================================
Task(14.1): Templates:
======================
|    Requirements:
|        Create Generic stack class based on templates : implement generic
|        functions for push and pop elements
|
========================================================================================================
*/
/*
========================================================================================================
Task(14.1): Templates - Generic Stack Implementation
========================================================================================================
| Data Structures & Templates Summary:
| - A stack is a Last-In-First-Out (LIFO) data structure.
| - Supports two main operations:
|     * push(x): Add element x to the top of the stack.
|     * pop(): Remove and return the top element.
| - Generic stacks can be implemented using C++ templates to work with any data type.
| - Internally, a stack can use an array, vector, or linked list.
| - This example uses a dynamic array for simplicity.
| - Templates allow code reuse and type safety for any stack element type.
| - Stacks are used in function calls, expression evaluation, undo features, etc.
========================================================================================================
*/
/*  ========================================================================================================
                            Included Libraries.
    ======================================================================================================== */
#include <iostream>
#include <stdexcept>

/*  ========================================================================================================
                            Generic Stack Class (Template) / Functions Prototype
    ======================================================================================================== */

template <typename T>
class Stack
{
private:
    T *arr;
    int capacity;
    int top;

public:
    Stack(int size = 100);
    ~Stack();
    bool isEmpty() const;
    int size() const;
    void push(const T &value);
    T pop();
    T peek() const; // Max size.
    T top() const;  // Max size.
};

/*  ========================================================================================================
                        Entry Point
    ======================================================================================================== */
int main()
{
    Stack<int> intStack(5);
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    std::cout << "Top element: " << intStack.peek() << std::endl;
    std::cout << "Stack size: " << intStack.size() << std::endl;

    std::cout << "Popped: " << intStack.pop() << std::endl;
    std::cout << "Popped: " << intStack.pop() << std::endl;

    Stack<std::string> strStack(3);
    strStack.push("Hello");
    strStack.push("World");

    std::cout << "Top string: " << strStack.peek() << std::endl;
    std::cout << "Popped string: " << strStack.pop() << std::endl;

    return 0;
}

/*  ========================================================================================================
                        Functions implementation
    ======================================================================================================== */
template <typename T>
Stack<T>::Stack(int size) : capacity(size), top(-1)
{
    std::cout << "Constructor Called: Stack.\n";
    arr = new T[capacity];
}

template <typename T>
Stack<T>::~Stack()
{
    std::cout << "Destructor Called: Stack.\n";
    delete[] arr;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return top < 0;
}

template <typename T>
int Stack<T>::size() const
{
    return top + 1;
}

template <typename T>
void Stack<T>::push(const T &value)
{
    if (top >= capacity - 1)
        throw std::overflow_error("Stack overflow");

    arr[++top] = value;
}

template <typename T>
T Stack<T>::pop()
{
    if (top < 0)
        throw std::underflow_error("Stack underflow");

    return arr[top--];
}

template <typename T>
T Stack<T>::peek() const
{
    if (top < 0)
        throw std::underflow_error("Stack is empty");

    return arr[top];
}

template <typename T>
T Stack<T>::top() const
{
    if (top < 0)
        throw std::underflow_error("Stack is empty");

    return arr[top];
}