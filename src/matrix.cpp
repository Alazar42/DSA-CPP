#include <iostream>
#include <vector>

#include "matrix.hpp"

int main(int argc, char const *argv[])
{
    std::vector<int> a = {
        15, 2, 1, 18};
    Matrix array(a, 2, 2);

    std::cout << "\nStarting Matrix: \n";
    array.print_list();

    double det = array.determinant();
    std::cout << "\nDeterminant: " << det << std::endl;

    Matrix At = array.transpose();

    std::cout << "\nTransposed Matrix: \n";
    At.print_list();

    Matrix A_inv = array.inverse();
    std::cout << "\nInverted Matrix: \n";
    A_inv.print_list();

    return 0;
}