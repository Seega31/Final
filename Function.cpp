#include <iostream>
#include <string>
#include <cmath>

// Функция для конвертации числа из одной системы счисления в другую
std::string convertBase(std::string num, int fromBase, int toBase) {
    // Перевод числа в десятичную систему
    int decimalNum = 0;
    int length = num.length();
    for (int i = 0; i < length; i++) {
        int digit = (num[i] >= '0' && num[i] <= '9') ? (num[i] - '0') : (num[i] - 'A' + 10);
        decimalNum += digit * std::pow(fromBase, length - 1 - i);
    }

    // Конвертация десятичного числа в целевую систему счисления
    std::string result = "";
    while (decimalNum > 0) {
        int digit = decimalNum % toBase;
        char digitChar = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
        result = digitChar + result;
        decimalNum /= toBase;
    }

    return result;
}