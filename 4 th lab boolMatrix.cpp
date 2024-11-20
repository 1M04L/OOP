//boolMatrix.h

#include <iostream>
#include <vector>

class BoolMatrix {
private:
  std::vector<std::vector<bool>> matrix;
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
  std::vector<bool>& operator[](size_t row);
  const std::vector<bool>& operator[](size_t row) const;
  BoolMatrix operator&(const BoolMatrix& other) const;
  BoolMatrix& operator&=(const BoolMatrix& other);
  BoolMatrix operator|(const BoolMatrix& other) const;
  BoolMatrix& operator|=(const BoolMatrix& other);
};






//boolMatrix.cpp

#include "boolMatrix.h"
#include <algorithm>

BoolMatrix::BoolMatrix() : rows(0), cols(0) {}

BoolMatrix::BoolMatrix(size_t rows, size_t cols, bool value) : rows(rows), cols(cols) {
    matrix.resize(rows, std::vector<bool>(cols, value));
}

BoolMatrix::BoolMatrix(const std::vector<std::string>& charMatrix) {
    rows = charMatrix.size();
    if (rows > 0) {
        cols = charMatrix[0].length();
        matrix.resize(rows, std::vector<bool>(cols));
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                matrix[i][j] = (charMatrix[i][j] == '1');
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
        for (size_t j = 0; j < matrix.cols; ++j) {
            os << matrix.matrix[i][j];
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, BoolMatrix& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        for (size_t j = 0; j < matrix.cols; ++j) {
            char c;
            is >> c;
            matrix.matrix[i][j] = (c == '1');
        }
    }
    return is;
}

size_t BoolMatrix::getWeight() const {
    size_t weight = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (matrix[i][j]) {
                weight++;
            }
        }
    }
    return weight;
}


std::vector<bool> BoolMatrix::conjunction() const {
    if (rows == 0) return {};
    std::vector<bool> result(cols, true);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result[j] &= matrix[i][j];
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

std::vector<bool>& BoolMatrix::operator[](size_t row) {
    return matrix[row];
}

const std::vector<bool>& BoolMatrix::operator[](size_t row) const {
    return matrix[row];
}

BoolMatrix BoolMatrix::operator&(const BoolMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrices must have the same dimensions for & operation");
    }
    BoolMatrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result[i][j] = matrix[i][j] && other[i][j];
        }
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
        for (size_t j = 0; j < cols; ++j) {
            result[i][j] = matrix[i][j] || other[i][j];
        }
    }
    return result;
}

BoolMatrix& BoolMatrix::operator|=(const BoolMatrix& other) {
    *this = *this | other;
    return *this;
}







//main.cpp

#include <iostream>
#include <vector>
#include "boolMatrix.h"

int main() {
 
    BoolMatrix m1(3, 4, true);
    BoolMatrix m2(3, 4);
    std::vector<std::string> charMatrix = {"1010", "0101", "1100"};
    BoolMatrix m3(charMatrix);
    BoolMatrix m4 = m1;


    std::cout << "M1:\n" << m1 << std::endl;
    std::cout << "M2:\n" << m2 << std::endl;
    std::cout << "M3:\n" << m3 << std::endl;
    std::cout << "M4:\n" << m4 << std::endl;

    std::cout << "Rows M1: " << m1.getRows() << ", Cols M1: " << m1.getCols() << std::endl;
    std::cout << "Weight M1: " << m1.getWeight() << std::endl;
    std::cout << "Conjunction M1: ";
    for (bool b : m1.conjunction()) std::cout << b;
    std::cout << std::endl;


    m1.swap(m2);
    std::cout << "After swap:\n";
    std::cout << "M1:\n" << m1 << std::endl;
    std::cout << "M2:\n" << m2 << std::endl;

    BoolMatrix m5 = m1 & m3;
    std::cout << "M1 & M3:\n" << m5 << std::endl;

    m1 &= m3;
    std::cout << "M1 &= M3:\n" << m1 << std::endl;

    m2 |= m3;
    std::cout << "M2 |= M3:\n" << m2 << std::endl;

    return 0;
}
