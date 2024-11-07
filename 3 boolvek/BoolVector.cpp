
#include "BoolVektor.h"
#include <assert.h>
#include <utility>
#include <iostream>
#include <cstring>

BoolVector::BoolVector(int length) : m_length(length)
{
    m_cellCount = (length + CellSize - 1) / CellSize;
    m_cells = new Cell[m_cellCount];
    for (int i = 0; i < m_cellCount; i++) {
        m_cells[i] = 0; // Инициализация nulyami
    }
}

BoolVector::BoolVector(int length, bool value) : m_length(length) 
{
    m_cellCount = (length + CellSize - 1) / CellSize;
    m_cells = new Cell[m_cellCount];

    for (int i = 0; i < m_cellCount; i++) {
        if (value) {
            m_cells[i] = 0xFF; // Заполнение единицами
        } else {
            m_cells[i] = 0; 
        }
    }
}

BoolVector::BoolVector(const char* str) : m_length(strlen(str))
{
    m_cellCount = (m_length + CellSize - 1) / CellSize;
    m_cells = new Cell[m_cellCount];
    for (int i = 0; i < m_length; i++) {
        setBitValue(i, str[i] == '1');
    }
}

BoolVector::BoolVector(const BoolVector& other)
{
    m_length = other.m_length;
    m_cellCount = other.m_cellCount;
    m_cells = new Cell[m_cellCount];
    for (int i = 0; i < m_cellCount; i++) {
        m_cells[i] = other.m_cells[i]; 
    }
}

BoolVector::~BoolVector()
{
    delete[] m_cells;
}

int BoolVector::length() const
{
    return m_length;
}

void BoolVector::swap(BoolVector& other)
{
    std::swap(m_cells, other.m_cells);
    std::swap(m_cellCount, other.m_cellCount);
    std::swap(m_length, other.m_length);
}

bool BoolVector::bitValue(int index) const
{
    assert(index >= 0 && index < m_length);
    Cell mask = _mask(index);
    return m_cells[index / CellSize] & mask;
}

void BoolVector::setBitValue(int index, bool value)
{
    assert(index >= 0 && index < m_length);
    Cell mask = _mask(index);
    if (value) {
        m_cells[index / CellSize] |= mask;
    } else {
        m_cells[index / CellSize] &= ~mask;
    }
}

BoolVector& BoolVector::operator=(const BoolVector& other)
{
    if (this != &other) {
        delete[] m_cells;
        m_length = other.m_length;
        m_cellCount = other.m_cellCount;
        m_cells = new Cell[m_cellCount];
        for (int i = 0; i < m_cellCount; i++) {
            m_cells[i] = other.m_cells[i]; // Копирование по элементам
        }
    }
    return *this;
}

BoolVector::Rank BoolVector::operator[](int index) const
{
    assert(index >= 0 && index < m_length);
    return Rank(&m_cells[index / CellSize], _mask(index));
}
int BoolVector::_excessRankCount() const
{    
    return (m_cellCount * CellSize - m_length);
}

BoolVector::Cell BoolVector::_mask(int index)
{
    Cell mask = 1;
    mask <<= CellSize - 1 - (index % CellSize);
    return mask;
}

BoolVector::Rank::Rank(const Cell* cell, Cell mask)
    : m_cell(cell)
    , m_mask(mask)
{
    assert(m_cell != nullptr);
    assert(m_mask > 0);
}

BoolVector::Rank& BoolVector::Rank::operator&=(const Rank& other)
{
    *const_cast<Cell*>(m_cell) &= *other.m_cell;
    return *this;
}

BoolVector::Rank& BoolVector::Rank::operator|=(const Rank& other)
{
    *const_cast<Cell*>(m_cell) |= *other.m_cell;
    return *this;
}

BoolVector::Rank& BoolVector::Rank::operator^=(const Rank& other)
{
    *const_cast<Cell*>(m_cell) ^= *other.m_cell;
    return *this;
}

BoolVector::Rank BoolVector::Rank::operator~() const
{
    return Rank(m_cell, ~m_mask);
}

BoolVector::Rank::operator bool() const
{
    return (*m_cell & m_mask) != 0;
}



BoolVector BoolVector::operator&(const BoolVector& other) const
{
    assert(m_length == other.m_length);
    BoolVector result(m_length);
    for (int i = 0; i < m_cellCount; i++) {
        result.m_cells[i] = m_cells[i] & other.m_cells[i];
    }
    return result;
}

BoolVector& BoolVector::operator&=(const BoolVector& other)
{
    assert(m_length == other.m_length);
    for (int i = 0; i < m_cellCount; i++) {
        m_cells[i] &= other.m_cells[i];
    }
    return *this;
}

BoolVector BoolVector::operator|(const BoolVector& other) const
{
    assert(m_length == other.m_length);
    BoolVector result(m_length);
    for (int i = 0; i < m_cellCount; i++) {
        result.m_cells[i] = m_cells[i] | other.m_cells[i];
    }
    return result;
}

BoolVector& BoolVector::operator|=(const BoolVector& other)
{
    assert(m_length == other.m_length);
    for (int i = 0; i < m_cellCount; i++) {
        m_cells[i] |= other.m_cells[i];
    }
    return *this;
}

BoolVector BoolVector::operator^(const BoolVector& other) const
{
    assert(m_length == other.m_length);
    BoolVector result(m_length);
    for (int i = 0; i < m_cellCount; i++) {
        result.m_cells[i] = m_cells[i] ^ other.m_cells[i];
    }
    return result;
}

BoolVector BoolVector::operator~() const
{
    BoolVector result(m_length);
    for (int i = 0; i < m_cellCount; i++) {
        result.m_cells[i] = ~m_cells[i];
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, const BoolVector& bv) {
    for (int i = 0; i < bv.length(); i++) {
        out << bv.bitValue(i);
    }
    return out;
}



void BoolVector::invertAll() {
    for (int i = 0; i < m_cellCount; i++) {
        m_cells[i] = ~m_cells[i]; 
    }
}

void BoolVector::setAllToZero() {
    for (int i = 0; i < m_cellCount; i++) {
        m_cells[i] = 0;
    }
}



std::istream& operator>>(std::istream& in, BoolVector& bv) {
    std::string str;
    in >> str;
    bv.m_length = str.length();
    bv.m_cellCount = (bv.m_length + BoolVector::CellSize - 1) / BoolVector::CellSize;
    bv.m_cells = new BoolVector::Cell[bv.m_cellCount];
    bv.setAllToZero();
    for (int i = 0; i < bv.m_length; i++) {
        bv.setBitValue(i, str[i] == '1');
    }
    return in;
}
