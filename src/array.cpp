#include<iostream>

int main(int argc, char const *argv[])
{
    // Integer array using immediate Value for array size and not assigning any values.
    int array[10] = {1, 2, 3, 4, 5};
    /* Getting array size since there is no direct way of getting that value in C++.
    We don't have to do the array size calculations if we are going to do the following For Range Loop.*/
    int array_size = sizeof(array - array[0]);
    
    // Printing All Values.
    std::cout << "Array Before Adding The Values." << std::endl;
    for (auto &&i : array)
    {
        std::cout << i << std::endl;
    }

    // Adding values to the rest free memory on the array.
    for (size_t i = 0; i <= array_size; i++)
    {
        if (i >= 5)
        {
            array[i] = i + 1;
        }
    }
    
    // Printing All Values.
    std::cout << "Array After Adding The Values." << std::endl;
    for (auto &&i : array)
    {
        std::cout << i << std::endl;
    }
    
    return 0;
}
