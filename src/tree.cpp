#include "tree.hpp"

int main(int argc, char const *argv[])
{
    Tree root(0, 5);
    Tree *first_node = root.add_child(1, 2);
    Tree *second_node = root.add_child(2, 2);
    Tree *third_node = root.add_child(3, 2);
    Tree *fourth_node = root.add_child(4, 2);
    Tree *fivth_node = root.add_child(5, 2);

    if (first_node != nullptr)
    {
        Tree *child1_1 = first_node->add_child(10, 2);
        Tree *child1_2 = first_node->add_child(11, 2);

        if (child1_1 && child1_2)
        {
            child1_1->add_child(100, 0);
            child1_1->add_child(101, 0);
            child1_2->add_child(110, 0);
            child1_2->add_child(111, 0);
        }
        
    }

    if (second_node != nullptr)
    {
        Tree *child2_1 = second_node->add_child(20, 2);
        Tree *child2_2 = second_node->add_child(21, 2);

        if (child2_1 && child2_2)
        {
            child2_1->add_child(200, 0);
            child2_1->add_child(201, 0);
            child2_2->add_child(210, 0);
            child2_2->add_child(211, 0);
        }
    }

    if (third_node != nullptr)
    {
        Tree *child3_1 = third_node->add_child(30, 2);
        Tree *child3_2 = third_node->add_child(31, 2);

        if (child3_1 && child3_2)
        {
            child3_1->add_child(300, 0);
            child3_1->add_child(301, 0);
            child3_2->add_child(310, 0);
            child3_2->add_child(311, 0);
        }
    }

    if (fourth_node != nullptr)
    {
        Tree *child4_1 = fourth_node->add_child(40, 2);
        Tree *child4_2 = fourth_node->add_child(41, 2);

        if (child4_1 && child4_2)
        {
            child4_1->add_child(400, 0);
            child4_1->add_child(401, 0);
            child4_2->add_child(410, 0);
            child4_2->add_child(411, 0);
        }
    }

    if (fivth_node != nullptr)
    {
        Tree *child5_1 = fivth_node->add_child(50, 2);
        Tree *child5_2 = fivth_node->add_child(51, 2);

        if (child5_1 && child5_2)
        {
            child5_1->add_child(500, 0);
            child5_1->add_child(501, 0);
            child5_2->add_child(510, 0);
            child5_2->add_child(511, 0);
        }
    }

    root.print_tree();
    return 0;
}
