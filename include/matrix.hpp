#include <iostream>
#include <vector>
#include <cmath>
#include <iostream>
#include <vector>
#include <cmath>

// NOTE: Matrix module is still in progress and not feature-complete yet.

class Matrix
{
private:
    std::vector<double> data;
    int row;
    int column;

public:
    Matrix(std::vector<int> data, int row, int column)
    {
        if (data.size() != (row * column))
        {
            std::cerr << "Error: Array size = " << data.size() << " is different from row * column.";
            std::exit(1);
        }
        else
        {
            this->data.assign(data.begin(), data.end());
            this->row = row;
            this->column = column;
        }
    }

    Matrix(std::vector<double> data, int row, int column)
    {
        if (data.size() != (row * column))
        {
            std::cerr << "Error: Array size is different from row * column.";
            std::exit(1);
        }
        else
        {
            this->data = data;
            this->row = row;
            this->column = column;
        }
    }

    static Matrix identity(int size)
    {
        std::vector<double> identity_data(size * size, 0.0);
        for (int i = 0; i < size; ++i)
        {
            identity_data[i * size + i] = 1.0;
        }
        return Matrix(identity_data, size, size);
    }

    static Matrix zero(int row, int column)
    {
        std::vector<double> zero_data(row * column, 0.0);
        return Matrix(zero_data, row, column);
    }

    static Matrix ones(int row, int column)
    {
        std::vector<double> ones_data(row * column, 1.0);
        return Matrix(ones_data, row, column);
    }

    static Matrix random(int row, int column, double min_value = 0.0, double max_value = 1.0)
    {
        std::vector<double> random_data(row * column);
        for (size_t i = 0; i < random_data.size(); ++i)
        {
            random_data[i] = min_value + static_cast<double>(rand()) / RAND_MAX * (max_value - min_value);
        }
        return Matrix(random_data, row, column);
    }

    static Matrix random(int row, int column, int min_value = 0, int max_value = 1)
    {
        if (min_value > max_value)
        {
            std::cerr << "Error: min_value must be less than or equal to max_value.";
            std::exit(1);
        }

        std::vector<int> random_data(row * column);
        int range = max_value - min_value + 1;
        for (size_t i = 0; i < random_data.size(); ++i)
        {
            random_data[i] = min_value + (std::rand() % range);
        }
        return Matrix(random_data, row, column);
    }

    auto determinant() const
    {
        if (this->row != this->column)
        {
            std::cerr << "Error: Determinant exists only for square matrices.";
            std::exit(1);
        }

        int n = this->row;
        const double EPS = 1e-12;
        std::vector<double> lu = this->data;
        int swap_count = 0;

        // LU decomposition with partial pivoting.
        for (int k = 0; k < n; ++k)
        {
            int pivot_row = k;
            double max_abs = std::fabs(lu[k * n + k]);

            for (int i = k + 1; i < n; ++i)
            {
                double candidate = std::fabs(lu[i * n + k]);
                if (candidate > max_abs)
                {
                    max_abs = candidate;
                    pivot_row = i;
                }
            }

            if (max_abs < EPS)
            {
                return 0.0; // Singular matrix
            }

            if (pivot_row != k)
            {
                for (int j = 0; j < n; ++j)
                {
                    std::swap(lu[k * n + j], lu[pivot_row * n + j]);
                }
                ++swap_count;
            }

            for (int i = k + 1; i < n; ++i)
            {
                lu[i * n + k] /= lu[k * n + k];
                double lik = lu[i * n + k];
                for (int j = k + 1; j < n; ++j)
                {
                    lu[i * n + j] -= lik * lu[k * n + j];
                }
            }
        }

        double det = (swap_count % 2 == 0) ? 1.0 : -1.0;
        for (int i = 0; i < n; ++i)
        {
            det *= lu[i * n + i];
        }

        return det;
    }

    Matrix transpose() const
    {
        Matrix transpose_matrix(data, this->column, this->row);

        for (size_t i = 0; i < this->row; ++i)
        {
            for (size_t j = 0; j < this->column; ++j)
            {
                transpose_matrix.data[j * this->row + i] = this->data[i * this->column + j];
            }
        }

        return transpose_matrix;
    }

    Matrix inverse() const
    {
        if (this->row != this->column)
        {
            std::cerr << "Error: Inverse exists only for square matrices.";
            std::exit(1);
        }

        int n = this->row;
        const double EPS = 1e-12;
        std::vector<double> lu = this->data;
        std::vector<int> piv(n);

        for (int i = 0; i < n; ++i)
        {
            piv[i] = i;
        }

        // LU decomposition with partial pivoting: PA = LU.
        for (int k = 0; k < n; ++k)
        {
            int pivot_row = k;
            double max_abs = std::fabs(lu[k * n + k]);

            for (int i = k + 1; i < n; ++i)
            {
                double candidate = std::fabs(lu[i * n + k]);
                if (candidate > max_abs)
                {
                    max_abs = candidate;
                    pivot_row = i;
                }
            }

            if (max_abs < EPS)
            {
                std::cerr << "Error: Matrix is singular, inverse does not exist.";
                std::exit(1);
            }

            if (pivot_row != k)
            {
                for (int j = 0; j < n; ++j)
                {
                    std::swap(lu[k * n + j], lu[pivot_row * n + j]);
                }
                std::swap(piv[k], piv[pivot_row]);
            }

            for (int i = k + 1; i < n; ++i)
            {
                lu[i * n + k] /= lu[k * n + k];
                double lik = lu[i * n + k];
                for (int j = k + 1; j < n; ++j)
                {
                    lu[i * n + j] -= lik * lu[k * n + j];
                }
            }
        }

        std::vector<double> inverse_data(n * n, 0.0);
        std::vector<double> y(n, 0.0);
        std::vector<double> x(n, 0.0);

        // Solve A * x = e_col for each column of the inverse using LU.
        for (int col = 0; col < n; ++col)
        {
            for (int i = 0; i < n; ++i)
            {
                double rhs = (piv[i] == col) ? 1.0 : 0.0;
                for (int j = 0; j < i; ++j)
                {
                    rhs -= lu[i * n + j] * y[j];
                }
                y[i] = rhs;
            }

            for (int i = n - 1; i >= 0; --i)
            {
                double rhs = y[i];
                for (int j = i + 1; j < n; ++j)
                {
                    rhs -= lu[i * n + j] * x[j];
                }
                x[i] = rhs / lu[i * n + i];
            }

            for (int i = 0; i < n; ++i)
            {
                inverse_data[i * n + col] = x[i];
            }
        }

        Matrix inverse_matrix(inverse_data, n, n);

        return inverse_matrix;
    }

    static Matrix addition(const Matrix &A, const Matrix &B)
    {
        if (A.row != B.row || A.column != B.column)
        {
            std::cerr << "Error: Matrices must have the same dimensions for addition.";
            std::exit(1);
        }

        std::vector<double> result_data(A.data.size());

        for (size_t i = 0; i < A.data.size(); ++i)
        {
            result_data[i] = A.data[i] + B.data[i];
        }

        return Matrix(result_data, A.row, A.column);
    }

    static Matrix subtraction(const Matrix &A, const Matrix &B)
    {
        if (A.row != B.row || A.column != B.column)
        {
            std::cerr << "Error: Matrices must have the same dimensions for subtraction.";
            std::exit(1);
        }

        std::vector<double> result_data(A.data.size());

        for (size_t i = 0; i < A.data.size(); ++i)
        {
            result_data[i] = A.data[i] - B.data[i];
        }

        return Matrix(result_data, A.row, A.column);
    }

    static Matrix multiplication(const Matrix &A, const Matrix &B)
    {
        if (A.column != B.row)
        {
            std::cerr << "Error: Number of columns in A must equal number of rows in B for multiplication.";
            std::exit(1);
        }

        std::vector<double> result_data(A.row * B.column, 0.0);

        for (size_t i = 0; i < A.row; ++i)
        {
            for (size_t j = 0; j < B.column; ++j)
            {
                double sum = 0.0;
                for (size_t k = 0; k < A.column; ++k)
                {
                    sum += A.data[i * A.column + k] * B.data[k * B.column + j];
                }
                result_data[i * B.column + j] = sum;
            }
        }

        return Matrix(result_data, A.row, B.column);
    }

    static Matrix division(const Matrix &A, const Matrix &B)
    {
        if (B.row != B.column)
        {
            std::cerr << "Error: B must be a square matrix for division.";
            std::exit(1);
        }

        Matrix B_inv = B.inverse();
        return multiplication(A, B_inv);
    }

    void print_list()
    {

        for (size_t i = 0; i < this->data.size(); i++)
        {
            // std::cout << i % this->row;
            if (i % this->column == this->column - 1)
            {
                std::cout << this->data[i] << "]" << "\n";
            }
            else if (i % this->column == 0)
            {
                std::cout << "[" << this->data[i] << ", ";
            }
            else
            {
                std::cout << "" << this->data[i] << ", ";
            }
        }
    }
};