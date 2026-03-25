#include <iostream>

class Stack
{
private:
    int stack[100];
    int top_index;

public:
    Stack()
    {
        for (int i = 0; i < 100; i++)
        {
            stack[i] = 0;
        }
        top_index = 0;
    }

    int pop()
    {
        stack[top_index] = 0;
        top_index--;
        return stack[0];
    }

    void push(int data)
    {
        stack[top_index] = data;
        top_index++;
    }

    void print_stack()
    {
        int size = sizeof(stack - stack[0]);
        for (int i = 0; i < top_index; i++)
        {
            std::cout << "Element" << i << ":" << stack[i] << std::endl;
        }
    }

    ~Stack()
    {
        free(stack);
    }
};