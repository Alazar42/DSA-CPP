#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Tree
{
private:
    int data;
    int child_index = 0;
    int children_size = 0;
    std::vector<std::unique_ptr<Tree>> children;

    void print_tree_impl(const std::string &prefix, bool is_last) const
    {
        std::cout << prefix;
        if (is_last)
        {
            std::cout << "|__ ";
        }
        else
        {
            std::cout << "|-- ";
        }
        std::cout << data << std::endl;

        for (std::size_t i = 0; i < children.size(); i++)
        {
            const bool child_is_last = (i + 1 == children.size());
            children[i]->print_tree_impl(prefix + (is_last ? "    " : "|   "), child_is_last);
        }
    }

public:
    Tree(int data, int children_size)
    {
        if (children_size < 0)
        {
            children_size = 0;
        }
        this->children_size = children_size;
        this->children.reserve(children_size);
        this->data = data;
    }

    Tree *add_child(int data, int new_child_children_size)
    {
        if (this->child_index < this->children_size)
        {
            this->children.push_back(std::make_unique<Tree>(data, new_child_children_size));
            child_index++;
            return this->children.back().get();
        }
        else
        {
            std::cout << "Error: child size exceeded; cannot add new child." << std::endl;
            return nullptr;
        }
    }

    void print_tree() const
    {
        std::cout << data << std::endl;
        for (std::size_t i = 0; i < children.size(); i++)
        {
            const bool child_is_last = (i + 1 == children.size());
            children[i]->print_tree_impl("", child_is_last);
        }
    }
};