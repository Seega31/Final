#include <iostream>
#include <string>
#include <cmath>

    // Функция для конвертации числа из одной системы счисления в другую
    std::string convertBase(std::string num, int fromBase, int toBase) {
    // Перевод числа в десятичную систему
    int decimalNum = 0;
    int length = num.length();
    for (int i = 0; i < length; i++) {
        int digit;
        if (num[i] >= '0' && num[i] <= '9') {
            digit = num[i] - '0';
        }
        else {
            digit = num[i] - 'A' + 10;
        }
        decimalNum += digit * std::pow(fromBase, length - 1 - i);
    }
    // Конвертация десятичного числа в целевую систему счисления
    std::string result = "";
    while (decimalNum > 0) {
        int digit = decimalNum % toBase;
        char digit1;
        if (digit < 10) {
            digit1 = '0' + digit;
        }
        else {
            digit1 = 'A' + digit - 10;
        }
        result = digit1 + result;
        decimalNum /= toBase;
    }
    return result;
}
    int main() {
    setlocale(LC_ALL, "Russian");
    std::string num;
    int fromBase, toBase;
    std::cout << "Введите число->";    
    std::cin >> num;
    std::cout << "Введите систему счисления ->";
    std::cin >> fromBase;
    std::cout << "Введите целелевую систему счисления -> ";
    std::cin >> toBase;
    std::string convertedNum = convertBase(num, fromBase, toBase);
    std::cout << "Результат конвертации: " << convertedNum << std::endl;

    return 0;
    }