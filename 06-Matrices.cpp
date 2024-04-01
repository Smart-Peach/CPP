#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    size_t rows, cols;

public:
    // Constructor
    Matrix(size_t size) : Matrix(std::vector<double>(size, 0.0)) { }

    // Constructor from 1D std::vector of doubles (elements on main diagonal)
    Matrix(const std::vector<double>& diagonalElements) {
        rows = diagonalElements.size();
        cols = diagonalElements.size();

        data.resize(rows, std::vector<double>(cols, 0.0));

        for (size_t i = 0; i < rows; ++i) {
            data[i][i] = diagonalElements[i];
        }
    }

    // Destructor
    ~Matrix() { }

    // Type conversion operator to double
    explicit operator double() const {
        double sum = 0.0;
        for (size_t i = 0; i < rows; ++i) {
            sum += data[i][i]; // calculating sum of main diagonal elements
        }
        return sum;
    }

    // Overloaded operator for matrix addition
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions don't match for addition.");
        }

        Matrix result(rows);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    // Overloaded operator for matrix addition assignment
    Matrix& operator+=(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions don't match for addition.");
        }

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                data[i][j] += other.data[i][j];
            }
        }

        return *this;
    }

    // Overloaded operator for matrix multiplication
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication.");
        }

        Matrix result(rows);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    // Overloaded operator for matrix scalar multiplication
    Matrix operator*(const double scalar) const {
        Matrix result(rows);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    // Overloaded operator for matrix scalar multiplication assignment
    Matrix& operator*=(const double scalar) {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                data[i][j] *= scalar;
            }
        }
        return *this;
    }

    // Overloaded operator for matrix equality check
    bool operator==(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            return false;
        }

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    // Overloaded operator for matrix inequality check
    bool operator!=(const Matrix& other) const {
        return !(*this == other);
    }

    // Helper function to display the matrix
    void display() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};


int main() {}