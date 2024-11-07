#pragma once
#include <iostream>
#include <cstring>

class BoolVector
{
public:
    class Rank;

public:
    using Cell = unsigned char;
    static const int CellSize = 8; // sizeof(Cell) * 8
    BoolVector(int length = CellSize);
    BoolVector(int length, bool value);
    BoolVector(const char* str); // Конструктор из массива const char *
    BoolVector(const BoolVector& other);
    ~BoolVector();

    int length() const;

    void swap(BoolVector& other);
    void invertAll();
    bool bitValue(int index) const;
    void setAllToZero();
    void setBitValue(int index, bool value);

    BoolVector& operator=(const BoolVector& other);
    Rank operator[](int index) const; // Получение компоненты (только чтение)

    BoolVector operator&(const BoolVector& other) const;
    BoolVector& operator&=(const BoolVector& other);
    BoolVector operator|(const BoolVector& other) const;
    BoolVector& operator|=(const BoolVector& other);
    BoolVector operator^(const BoolVector& other) const;
    BoolVector operator~() const;

    // Потоковый ввод/вывод
    friend std::ostream& operator<<(std::ostream& out, const BoolVector& bv);
    friend std::istream& operator>>(std::istream& in, BoolVector& bv);

private:
    int _excessRankCount() const;
    static Cell _mask(int index);

private:
    Cell* m_cells = nullptr;
    int m_cellCount = 0;
    int m_length = 0;
};

class BoolVector::Rank
{
public:
   
    Rank(const Cell* cell, Cell mask); 

    Rank& operator&=(const Rank& other);
    Rank& operator|=(const Rank& other);
    Rank& operator^=(const Rank& other);
    Rank operator~() const;

    // Преобразование в bool
    operator bool() const; 

private:
    const Cell* m_cell = nullptr;
    Cell m_mask = 0;
};
