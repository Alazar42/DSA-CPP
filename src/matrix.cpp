#include <iostream>
#include <vector>

#include "matrix.hpp"

int main(int argc, char const *argv[])
{
    std::vector<int> a = {
        15, 2, 1, 18};

    std::vector<int> b = {
        10, 34, 1, 0};

    Matrix array(a, 2, 2);
    Matrix array2(b, 2, 2);
    Matrix identity_matrix = Matrix::identity(3);
    Matrix zero_matrix = Matrix::zero(3, 3);
    Matrix ones_matrix = Matrix::ones(3, 3);
    Matrix random_matrix = Matrix::random(3, 3, -1, 12);

    std::cout << "Zero Matrix: \n";
    zero_matrix.print_list();

    std::cout << "\nOnes Matrix: \n";
    ones_matrix.print_list();

    std::cout << "Identity Matrix: \n";
    identity_matrix.print_list();

    std::cout << "\nRandom Matrix: \n";
    random_matrix.print_list();

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

    Matrix sum = Matrix::addition(array, array2);
    std::cout << "\nSum of Matrices: \n";
    array.print_list();
    std::cout << "+\n";
    array2.print_list();
    std::cout << "=\n";
    sum.print_list();

    Matrix difference = Matrix::subtraction(array, array2);
    std::cout << "\nDifference of Matrices: \n";
    array.print_list();
    std::cout << "-\n";
    array2.print_list();
    std::cout << "=\n";
    difference.print_list();

    Matrix product = Matrix::multiplication(array, array2);
    std::cout << "\nProduct of Matrices: \n";
    array.print_list();
    std::cout << "*\n";
    array2.print_list();
    std::cout << "=\n";
    product.print_list();

    Matrix quotient = Matrix::division(array, array2);
    std::cout << "\nQuotient of Matrices: \n";
    array.print_list();
    std::cout << "/\n";
    array2.print_list();
    std::cout << "=\n";
    quotient.print_list();

    return 0;
}