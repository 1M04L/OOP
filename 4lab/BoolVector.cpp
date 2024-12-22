#include "BoolVector.h"
#include <algorithm>
#include <cassert>

std::_Bit_reference BoolVector::operator[](int index) {
    assert(index >= 0 && index < static_cast<int>(bits.size()));
    return bits[index];
}

bool BoolVector::operator[](int index) const {
    assert(index >= 0 && index < static_cast<int>(bits.size()));
    return bits[index];
}

BoolVector::BoolVector() {}

BoolVector::BoolVector(size_t size, bool value) {
    bits.resize(size, value);
}

BoolVector::BoolVector(const std::string& bitString) {
    for (char ch : bitString) {
        bits.push_back(ch == '1');
    }
}

BoolVector::BoolVector(const BoolVector& other) : bits(other.bits) {}

BoolVector::~BoolVector() {}

size_t BoolVector::length() const {
    return bits.size();
}

void BoolVector::invertAll() {
    std::transform(bits.begin(), bits.end(), bits.begin(), std::logical_not<bool>());
}

bool BoolVector::bitValue(size_t index) const {
    if (index < bits.size()) {
        return bits[index];
    }
    throw std::out_of_range("Index out of range");
}

BoolVector& BoolVector::operator=(const BoolVector& other) {
    if (this != &other) {
        bits = other.bits;
    }
    return *this;
}

BoolVector BoolVector::operator&(const BoolVector& other) const {
    size_t minSize = std::min(bits.size(), other.bits.size());
    BoolVector result(minSize);
    for (size_t i = 0; i < minSize; ++i) {
        result.bits[i] = bits[i] && other.bits[i];
    }
    return result;
}

BoolVector& BoolVector::operator&=(const BoolVector& other) {
    size_t minSize = std::min(bits.size(), other.bits.size());
    bits.resize(minSize);
    for (size_t i = 0; i < minSize; ++i) {
        bits[i] = bits[i] && other.bits[i];
    }
    return *this;
}

BoolVector BoolVector::operator|(const BoolVector& other) const {
    size_t minSize = std::min(bits.size(), other.bits.size());
    BoolVector result(minSize);
    for (size_t i = 0; i < minSize; ++i) {
        result.bits[i] = bits[i] || other.bits[i];
    }
    return result;
}

BoolVector& BoolVector::operator|=(const BoolVector& other) {
    size_t minSize = std::min(bits.size(), other.bits.size());
    bits.resize(minSize);
    for (size_t i = 0; i < minSize; ++i) {
        bits[i] = bits[i] || other.bits[i];
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const BoolVector& bv) {
    for (bool bit : bv.bits) {
        os << (bit ? '1' : '0');
    }
    return os;
}

std::istream& operator>>(std::istream& is, BoolVector& bv) {
    std::string input;
    is >> input;
    bv.bits.clear();
    for (char ch : input) {
        bv.bits.push_back(ch == '1');
    }
    return is;
}
