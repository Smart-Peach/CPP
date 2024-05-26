#include <iostream>
#include <vector>
#include <stdexcept>


class Row {
    double* data;
    size_t row_num;

public:
    Row(size_t size): row_num(size) {
        data = new double[size]();
    }

    Row() {}
    Row(const Row& other) {
        row_num = other.row_num;
        data = new double[row_num]();
        for (size_t i = 0 ; i < row_num; ++i) {
            data[i] = other.data[i];
        }
    }


    Row& operator=(const Row& other) {
        row_num = other.row_num;
        data = new double[row_num]();
        for (size_t i = 0 ; i < row_num; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    ~Row() {
        delete[] data;
        data = nullptr;
    }

    // for double indexing
    double& operator[](size_t index) {
        if (index > row_num - 1 || index < 0) throw std::out_of_range("Incorrect index for double indexing!");
        return data[index];
    }

    const double& operator[](size_t index) const {
        if (index > row_num - 1 || index < 0) throw std::out_of_range("Incorrect index for double indexing!");
        return data[index];
    }
};

class Matrix {
private:

    size_t size_m;
    Row* data;

public:
    // Constructor
    Matrix(size_t size) : size_m(size) { 
        data = new Row[size];
        for (int i = 0; i < size_m; ++i) {
            data[i] = Row(size);
        }
    }

    ~Matrix() {
        for (size_t i = 0; i < size_m; i++) {
            data[i].~Row();
        }
        delete[] data;
        data = nullptr;
    }

    // Constructor from 1D std::vector of doubles (elements on main diagonal)
    Matrix(const std::vector<double>& diagonalElements) : size_m(diagonalElements.size()) {
        data = new Row[size_m];
        for (int i = 0; i < size_m; ++i) {
            data[i] = Row(size_m);
        }

        for (size_t i = 0; i < size_m; ++i) {
            data[i][i] = diagonalElements[i];
        }
    }

    // Overloaded operator for MATRIX PLUS
    Matrix operator+(Matrix& other) const {
        if (size_m != other.size_m || size_m != other.size_m) {
            throw std::invalid_argument("Matrix dimensions don't match for addition.");
        }

        Matrix result(size_m);
        for (size_t i = 0; i < size_m; ++i) {
            for (size_t j = 0; j < size_m; ++j) {
                result.data[i][j] = data[i][j] + other[i][j];
            }
        }

        return result;
    }

    // Overloaded operator for matrix addition assignment
    Matrix& operator+=(Matrix& other) {
        if (size_m != other.size_m || size_m != other.size_m) {
            throw std::invalid_argument("Matrix dimensions don't match for addition.");
        }

        for (size_t i = 0; i < size_m; ++i) {
            for (size_t j = 0; j < size_m; ++j) {
                data[i][j] += other.data[i][j];
            }
        }

        return *this;
    }

    // Overloaded operator for MATRIX MULT
    Matrix operator*(const Matrix& other) const {
        if (size_m != other.size_m) {
            throw std::invalid_argument("Number of columns in the first matrix must be equal to the number of size_m in the second matrix for multiplication.");
        }

        Matrix result(size_m);
        for (size_t i = 0; i < size_m; ++i) {
            for (size_t j = 0; j < other.size_m; ++j) {
                for (size_t k = 0; k < size_m; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    // Overloaded operator for matrix SCALAR MULT
    Matrix operator*(const double scalar) const {
        Matrix result(size_m);
        for (size_t i = 0; i < size_m; ++i) {
            for (size_t j = 0; j < size_m; ++j) {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    friend Matrix operator*(const double scalar, Matrix& m) {
        return m * scalar;
    }

    // SCALAR PLUS
    Matrix operator+(const double scalar) const {
        Matrix result(size_m);
        for (size_t i = 0; i < size_m; ++i) {
            for (size_t j = 0; j < size_m; ++j) {
                result.data[i][j] = data[i][j] + scalar;
            }
        }
        return result;
    }

    friend Matrix operator+(const double scalar, Matrix& m) {
        return m + scalar;
    }

    // Overloaded operator for matrix scalar multiplication assignment
    Matrix& operator*=(double scalar) {
        for (size_t i = 0; i < size_m; ++i) {
            for (size_t j = 0; j < size_m; ++j) {
                data[i][j] *= scalar;
            }
        }
        return *this;
    }

    Matrix& operator+=(double scalar) {
        for (size_t i = 0; i < size_m; ++i) {
            for (size_t j = 0; j < size_m; ++j) {
                data[i][j] += scalar;
            }
        }
        return *this;
    }

    // Overloaded operator for matrix equality check
    bool operator==(const Matrix& other) const {
        if (size_m != other.size_m || size_m != other.size_m) {
            return false;
        }

        for (size_t i = 0; i < size_m; i++) {
            for (size_t j = 0; j < size_m; j++) {
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

    Row operator[](int index) {
        if (index > size_m - 1 || index < 0) throw std::out_of_range("Incorrect index for double indexing!");
        return data[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (size_t i = 0; i < matrix.size_m; ++i) {
            for (size_t j = 0; j < matrix.size_m; ++j) {
                os << matrix.data[i][j];
            }
            os << std::endl;
        }
        return os;
    }

    int get_size() { return size_m; }

    void filled_matrix() {    
        for (size_t i = 0; i < size_m; ++i) {
            for (size_t j = 0; j < size_m; ++j) {
                data[i][j] = i + j;
            }
        }
    }

    void e_matrix() {
        for (size_t i = 0; i < size_m; ++i) {
            for (size_t j = 0; j < size_m; ++j) {
                data[i][j] = 1;
            }
        }
    }
};
