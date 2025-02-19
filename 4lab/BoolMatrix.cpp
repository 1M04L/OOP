#include "BoolMatrix.h"
#include <algorithm>
#include <stdexcept>

BoolMatrix::BoolMatrix() : rows(0), cols(0) {}

BoolMatrix::BoolMatrix(size_t rows, size_t cols, bool value) : rows(rows), cols(cols) {
    matrix.resize(rows, BoolVector(cols, value));
}

BoolMatrix::BoolMatrix(const std::vector<std::string>& charMatrix) {
    rows = charMatrix.size();
    if (rows > 0) {
        cols = charMatrix[0].length();
        matrix.reserve(rows);
        for (const auto& rowStr : charMatrix) {
            matrix.emplace_back(rowStr); 
        }
    }
}

BoolMatrix::BoolMatrix(const BoolMatrix& other) 
    : rows(other.rows), cols(other.cols), matrix(other.matrix) {}

BoolMatrix::~BoolMatrix() {}

size_t BoolMatrix::getRows() const { return rows; }
size_t BoolMatrix::getCols() const { return cols; }

void BoolMatrix::swap(BoolMatrix& other) {
    std::swap(rows, other.rows);
    std::swap(cols, other.cols);
    std::swap(matrix, other.matrix);
}

std::ostream& operator<<(std::ostream& os, const BoolMatrix& bm) {
    for (const auto& vec : bm.matrix) {
        os << vec << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, BoolMatrix& bm) {
    for (auto& vec : bm.matrix) {
        is >> vec;
    }
    return is;
}

size_t BoolMatrix::getWeight() const {
    size_t weight = 0;
    for (const auto& vec : matrix) {
        for (int i = 0; i < vec.length(); ++i) {
            weight += vec.bitValue(i);
        }
    }
    return weight;
}

BoolVector BoolMatrix::conjunction() const {
    if (rows == 0) return BoolVector(cols, true);
    BoolVector result = matrix[0]; 
    for (size_t i = 1; i < rows; ++i) {
        result &= matrix[i]; 
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
