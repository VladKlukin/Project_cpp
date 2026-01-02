#include <iostream>
#include <string>
#include "Header.h" 
#include <ctime>
#include <clocale>
int main() {
    setlocale(LC_ALL, "rus");
    srand(time(NULL)); // инициализация генератора случайных чисел
    Sudoku solver; // создаём экземпляр решателя судоку
    SudokuGrid grid; // создаём пустую сетку 9x9
    std::cout << "<------------Menu----------->" << std::endl;
    std::cout << "1 - загрузить судоку из файла" << std::endl;
    std::cout << "2 - сгенерировать судоку" << std::endl;
    std::cout << "(пустое значение клетки в судоку отмечено точкой)" << std::endl;
    bool flag = true;
    int n = 0;
    std::cout << "Введите выбранную опцию: ";
    std::string input;
    while (flag) {
        try {
            getline(std::cin, input);
            n = stoi(input);
        }
        catch (std:: invalid_argument) {
            std::cerr << "Ошибка ввода, попробуйте снова!" << std::endl;
            continue;
        }
        if (n == 1 || n == 2) {
            flag = false;
        }
        else {
            std::cerr << "Ошибка ввода, попробуйте снова!" << std::endl;
        }
    }
    switch (n) {

    case 1: {
        solver.LoadGrid(grid);
        std::cout << "Загруженное судоку" << std::endl;
        solver.PrintGrid(grid);
        if (solver.CheckGrid(grid)) {
            solver.SolveSudoku(grid);
            solver.print(grid);
            break;
        }
        else {
            std::cout << "Поле не корректно";
            break;
        }
    }
    case 2: {
        bool success = false;
        do {
            // Пытаемся сгенерировать судоку
            success = solver.GenerateSudoku(grid);
        } while (!success);
        std::cout << "Сгенерированное судоку" << std::endl;
        solver.PrintGrid(grid);
        if (solver.CheckGrid(grid)) {
            solver.RemoveRandomNumber(grid);
            solver.SolveSudoku(grid);
            solver.print(grid);
            break;
        }
        else {
            std::cout << "Поле не корректно";
            break;
        }
        break;
    }
    default: {
        std::cout << "Ошибка ввода" << std::endl;
        break;
    }
    }
    return 0;
}
