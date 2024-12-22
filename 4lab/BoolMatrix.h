#pragma once
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
    BoolVector conjunction() const;

    BoolMatrix& operator=(const BoolMatrix& other);
    BoolVector& operator[](size_t row);
    const BoolVector& operator[](size_t row) const;

    BoolMatrix operator&(const BoolMatrix& other) const;
    BoolMatrix& operator&=(const BoolMatrix& other);
    BoolMatrix operator|(const BoolMatrix& other) const;
    BoolMatrix& operator|=(const BoolMatrix& other);
};
