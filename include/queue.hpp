#include <iostream>

class Queue
{
private:
    int queue[100];
    int first_index;

public:
    Queue()
    {
        for (int i = 0; i < 100; i++)
        {
            queue[i] = 0;
        }
        first_index = 0;
    }

    int deque()
    {
        int size = sizeof(queue - queue[0]);
        for (int i = 0; i <= first_index; i++)
        {
            queue[i - 1] = queue[i];
        }
        first_index--;
        return queue[0];
    }

    void enque(int data)
    {
        queue[first_index] = data;
        first_index++;
    }

    void print_queue()
    {
        int size = sizeof(queue - queue[0]);
        for (int i = 0; i < first_index; i++)
        {
            std::cout << "Element" << i << ":" << queue[i] << std::endl;
        }
    }
};