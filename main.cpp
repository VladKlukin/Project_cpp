#include <iostream>
#include <string>
#include "Header.h" 
#include <ctime>
#include <clocale>
int main() {
    setlocale(LC_ALL, "rus");
    srand(time(NULL)); // инициализаци€ генератора случайных чисел
    SudokuGrid grid; // создаЄм пустую сетку 9x9
    std::cout << "<---»нтерактивный решатель судоку--->" << std::endl;
    menu(grid);
    return 0;
}
