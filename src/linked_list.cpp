#include <iostream>
#include "linked_list.hpp"

int main(int argc, char const *argv[])
{
    LinkedList root(1);
    LinkedList second_node = root.add_node(2);
    LinkedList third_node = second_node.add_node(3);
    LinkedList fourth_node = third_node.add_node(4);
    LinkedList fivth_node = fourth_node.add_node(5);

    LinkedList first_node = LinkedList::insert_at_first(second_node, 0);
    LinkedList third_readded = LinkedList::insert_between(&second_node, &fourth_node, 3);
    LinkedList end_node = LinkedList::insert_at_end(root, 6);

    LinkedList::delete_node(third_node);

    root.print_linked_list();

    return 0;
}
