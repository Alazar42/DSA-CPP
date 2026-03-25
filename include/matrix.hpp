#include <iostream>
#include <vector>
#include <cmath>
#include <iostream>
#include <vector>
#include <cmath>

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

    auto determinant()
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

    Matrix transpose()
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

    Matrix inverse()
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