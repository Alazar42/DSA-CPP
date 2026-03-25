#include "queue.hpp"

int main(int argc, char const *argv[])
{
    Queue parser;

    parser.enque(0);
    parser.enque(1);
    parser.enque(2);
    parser.enque(3);
    parser.enque(4);
    parser.enque(5);

    parser.deque();

    parser.print_queue();
    return 0;
}
