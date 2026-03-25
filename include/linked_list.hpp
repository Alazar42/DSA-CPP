#include <iostream>

class LinkedList
{
private:
    int data;
public:
    
    LinkedList *next = nullptr;
    LinkedList *prev = nullptr;

    LinkedList(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    // This non static method creates a new node with a given data after the object which it called upon and returns the node
    LinkedList add_node(int data)
    {
        LinkedList new_node(data);
        new_node.next = this->next;
        new_node.prev = this;
        this->next = &new_node;
        return new_node;
    };

    // This method inserts the given data to the end of the linked list and returns the node
    static LinkedList insert_at_end(LinkedList node, int data)
    {
        LinkedList new_node(data);
        LinkedList *first_node = &node;
        while (first_node->next != nullptr)
        {
            first_node = first_node->next;
        }

        new_node.next = nullptr;
        new_node.prev = first_node;
        first_node->next = &new_node;

        return new_node;
    }

    // This method inserts the given data to the first of the linked list and returns the node
    static LinkedList insert_at_first(LinkedList node, int data)
    {
        LinkedList new_node(data);
        LinkedList *first_node = &node;
        while (first_node->prev != nullptr)
        {
            first_node = first_node->prev;
        }

        new_node.prev = nullptr;
        new_node.next = first_node;
        first_node->prev = &new_node;

        return new_node;
    }

    // This method inserts a new node with the data given between the given nodes and returns the node
    static LinkedList insert_between(LinkedList *prev, LinkedList *next, int data)
    {
        LinkedList new_node(data);
        new_node.next = next;
        new_node.prev = prev;
        next->prev = &new_node;
        prev->next = &new_node;

        return new_node;
    }

    /*  This method deletes the given node and reassign the prev and next nodes pointers
        deleting_node->prev->next = deleting_node->next;
        deleting_node->next->prev = deleting_node->prev; */
    static void delete_node(LinkedList node)
    {
        LinkedList *deleting_node = &node;
        deleting_node->prev->next = deleting_node->next;
        deleting_node->next->prev = deleting_node->prev;

        deleting_node->next = nullptr;
        deleting_node->prev = nullptr;
    }

    // From any node this method called upon it will print the whole linked list
    void print_linked_list()
    {
        LinkedList *first_node = this;
        // int counter = 1;

        if (first_node->prev != nullptr)
        {
            while (first_node->prev != nullptr)
            {
                first_node = first_node->prev;
            }
        }
        while (first_node->next != nullptr)
        {
            // std::cout << "Node: " << counter << std::endl;
            std::cout << "Data: " << first_node->data /* << "   This: " << first_node */ << std::endl;
            // std::cout << "Next: " << first_node->next << "   Prev: " << first_node->prev << std::endl;
            first_node = first_node->next;
            // counter++;
        }

        // std::cout << "Node: " << counter << std::endl;
        std::cout << "Data: " << first_node->data /* << "   This: " << first_node */ << std::endl;
        // std::cout << "Next: " << first_node->next << "   Prev: " << first_node->prev << std::endl;
    }

    ~LinkedList()
    {
        this->next = nullptr;
        this->prev = nullptr;
    }
};