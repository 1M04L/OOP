// boolMatrix.h

#include <iostream>
#include <vector>
#include "BoolVector.h"

class BoolMatrix {
private:
    std::vector<BoolVector> matrix;
    size_t rows;
    size_t cols;

public:
    BoolMatrix();
    BoolMatrix(size_t rows, size_t cols, bool value = false);
    BoolMatrix(const std::vector<std::string>& charMatrix);
    BoolMatrix(const BoolMatrix& other);
    ~BoolMatrix();

    size_t getRows() const;
    size_t getCols() const;

    void swap(BoolMatrix& other);

    friend std::ostream& operator<<(std::ostream& os, const BoolMatrix& matrix);
    friend std::istream& operator>>(std::istream& is, BoolMatrix& matrix);

    size_t getWeight() const;

    std::vector<bool> conjunction() const;

    BoolMatrix& operator=(const BoolMatrix& other);
    BoolVector& operator[](size_t row);
    const BoolVector& operator[](size_t row) const;

    BoolMatrix operator&(const BoolMatrix& other) const;
    BoolMatrix& operator&=(const BoolMatrix& other);
    BoolMatrix operator|(const BoolMatrix& other) const;
    BoolMatrix& operator|=(const BoolMatrix& other);
};

// boolMatrix.cpp
#include "BoolMatrix.h"
#include <algorithm>

BoolMatrix::BoolMatrix() : rows(0), cols(0) {}

BoolMatrix::BoolMatrix(size_t rows, size_t cols, bool value) : rows(rows), cols(cols) {
    matrix.resize(rows, BoolVector(cols, value));
}

BoolMatrix::BoolMatrix(const std::vector<std::string>& charMatrix) {
    rows = charMatrix.size();
    if (rows > 0) {
        cols = charMatrix[0].length();
        matrix.resize(rows, BoolVector(cols));
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                matrix[i].setBitValue(j, (charMatrix[i][j] == '1'));
            }
        }
    }
}

BoolMatrix::BoolMatrix(const BoolMatrix& other) : rows(other.rows), cols(other.cols), matrix(other.matrix) {}

BoolMatrix::~BoolMatrix() {}

size_t BoolMatrix::getRows() const { return rows; }
size_t BoolMatrix::getCols() const { return cols; }

void BoolMatrix::swap(BoolMatrix& other) {
    std::swap(rows, other.rows);
    std::swap(cols, other.cols);
    std::swap(matrix, other.matrix);
}

std::ostream& operator<<(std::ostream& os, const BoolMatrix& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        os << matrix.matrix[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, BoolMatrix& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        is >> matrix.matrix[i];
    }
    return is;
}

size_t BoolMatrix::getWeight() const {
    size_t weight = 0;
    for (size_t i = 0; i < rows; ++i) {
        weight += matrix[i].length(); 
    }
    return weight;
}

std::vector<bool> BoolMatrix::conjunction() const {
    if (rows == 0) return {};
    std::vector<bool> result(cols, true);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result[j] &= matrix[i].bitValue(j);  
        }
    }
    return result;
}

BoolMatrix& BoolMatrix::operator=(const BoolMatrix& other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        matrix = other.matrix;
    }
    return *this;
}

BoolVector& BoolMatrix::operator[](size_t row) {
    return matrix[row];
}

const BoolVector& BoolMatrix::operator[](size_t row) const {
    return matrix[row];
}

BoolMatrix BoolMatrix::operator&(const BoolMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrices must have the same dimensions for & operation");
    }
    BoolMatrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        result[i] = matrix[i] & other[i]; 
    }
    return result;
}

BoolMatrix& BoolMatrix::operator&=(const BoolMatrix& other) {
    *this = *this & other;
    return *this;
}

BoolMatrix BoolMatrix::operator|(const BoolMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrices must have the same dimensions for | operation");
    }
    BoolMatrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        result[i] = matrix[i] | other[i];  
    }
    return result;
}

BoolMatrix& BoolMatrix::operator|=(const BoolMatrix& other) {
    *this = *this | other;
    return *this;
}





