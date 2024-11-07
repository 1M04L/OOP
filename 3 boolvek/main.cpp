#include <iostream>
#include "BoolVektor.h"

int main() {
  
    BoolVector bv1;
    std::cout << "bv1: " << bv1 <<std:: endl; 

    // Конструктор(размер значение)
    BoolVector bv2(10, true);
    std::cout << "bv2: " << bv2 << std::endl;


    const char* str = "10101";
    BoolVector bv3(str);
    std::cout << "bv3: " << bv3 << std::endl;

    // Конструктор копирования
    BoolVector bv4 = bv2;
    std::cout << "bv4: " << bv4 << std::endl;

    // Длина 
    std::cout << "Длина bv2: " << bv2.length() << std::endl;

    // Обмен 
    bv2.swap(bv3);
    std::cout << "bv2: " << bv2 << std::endl;
    std::cout << "bv3: " << bv3 << std::endl;

    
    std::cout << "Введите BoolVector: ";
    std::cin >> bv1;
    std::cout << "bv1: " << bv1 << std::endl;

    // Инверси
    bv1.invertAll();
    std::cout << "bv1 (инвертированный): " << bv1 << std::endl;

    // Установка в 0/1 i-ой компоненты
    bv1.setBitValue(2, true);
    std::cout << "bv1 (установлен бит 2): " << bv1 << std::endl;

    bv1.setBitValue(4, false);
    std::cout << "bv1 (сброшен бит 4): " << bv1 << std::endl;

    // Получение компоненты (только чтение)
    std::cout << "bv1[3]: " << bv1[3] << std::endl; 

    // Пумножение
    BoolVector bv5 = bv2 & bv3;
    std::cout << "bv5 (bv2 & bv3): " << bv5 << std::endl;

    //сложение
    BoolVector bv6 = bv2 | bv3;
   std::cout << "bv6 (bv2 | bv3): " << bv6 <<std:: endl;

    //исключающее ИЛИ
    BoolVector bv7 = bv2 ^ bv3;
    std::cout << "bv7 (bv2 ^ bv3): " << bv7 << std::endl;

    //  инверсия
    BoolVector bv8 = ~bv2;
    std::cout << "bv8 (~bv2): " << bv8 << std::endl;

    // Присваивание
    bv1 = bv2;
    std::cout << "bv1 (после присваивания): " << bv1 << std::endl;

    return 0;
}
