#include <iostream>
#include "Array.h"

int main() {
    int initialValues[] = {5, 3, 8, -1,-1,-1, 2,2};
    Array<int> arr(initialValues, 5);

    std::cout << "Исходный массив: ";
    arr.print();

    arr.insert(2, 7);
    std::cout << "После вставки 7 на индекс 2: ";
    arr.print();

    arr.removeAt(4);
    std::cout << "После удаления элемента на индексе 4: ";
    arr.print();

    arr.removeByValue(3);
    std::cout << "После удаления элемента со значением 3: ";
    arr.print();

    int index = arr.find(8);
    std::cout << "Индекс элемента со значением 8: " << index << std::endl;

    arr.bubbleSort();
    std::cout << "Отсортированный массив: ";
    arr.print();

    Array<int> copiedArray = arr;
    std::cout << "Скопированный массив: ";
    copiedArray.print();

    arr.swap(copiedArray);
    std::cout << "Массив после обмена с копией: ";
    arr.print();

    std::cout << "Копия после обмена: ";
    copiedArray.print();

    int modeValue = arr.mode();
    std::cout <<  "  мода:  " << modeValue << std::endl;

    return 0;
}
