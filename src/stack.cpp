#include "stack.hpp"

int main(int argc, char const *argv[])
{
    Stack parser;

    parser.push(0);
    parser.push(1);
    parser.push(2);
    parser.push(3);
    parser.push(4);
    parser.push(5);

    parser.pop();

    parser.print_stack();
    return 0;
}
