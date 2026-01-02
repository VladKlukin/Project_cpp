#include <iostream>
#include <string>
#include <vector>
#include "Header.h"
#include <ctime>      
#include <cstdlib>    
#include <fstream>

auto Sudoku::GetRow(SudokuGrid& Sgrid, int row) {
	std::vector <int> result;
	for (int col = 0; col < 9; ++col) {
		result.push_back(Sgrid.grid[row][col]);
	}
	return result;
}
auto Sudoku::GetCol(SudokuGrid& Sgrid, int col) {
	std::vector <int> result;
	for (int row = 0; row < 9; ++row) {
		result.push_back(Sgrid.grid[row][col]);
	}
	return result;
}
auto Sudoku::getBlock(SudokuGrid& Sgrid, int block) {
	std::vector <int> result;
	int StartRow = block / 3 * 3;
	int StartCol = block % 3 * 3;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			result.push_back(Sgrid.grid[i + StartRow][j + StartCol]);
		}
	return result;
}
bool Sudoku::CanPlace(SudokuGrid& Sgrid, int row, int col, int num) {
	// Проверяем строку
	for (int x = 0; x < 9; x++) {
		if (Sgrid.grid[row][x] == num) return false;
	}

	// Проверяем столбец
	for (int y = 0; y < 9; y++) {
		if (Sgrid.grid[y][col] == num) return false;
	}

	// Проверяем блок
	int startRow = row - row % 3;
	int startCol = col - col % 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (Sgrid.grid[startRow + i][startCol + j] == num) return false;
		}
	}
	return true;
}
bool Sudoku::SolveSudoku(SudokuGrid& Sgrid) {
	for (int row = 0; row < 9; ++row)
		for (int col = 0; col < 9; ++col) {
			if (Sgrid.grid[row][col] == 0) {
				for (int num = 1; num <= 9; ++num) {
					if (CanPlace(Sgrid, row, col, num)) {
						Sgrid.grid[row][col] = num;
						if (SolveSudoku(Sgrid)) {
							return true;
						}
						Sgrid.grid[row][col] = 0;
					}
				}
				return false;
			}
		}
	return true;
}
void Sudoku::PrintGrid(SudokuGrid& Sgrid) {
	for (int row = 0; row < 9; ++row) {
		std::cout << "|";
		for (int col = 0; col < 9; ++col) {
			if (Sgrid.grid[row][col] == 0) {
				std::cout << " . "; // Светло-серый на чёрном фоне
			}
			else {
				std::cout << " " << Sgrid.grid[row][col] << " ";
			}
		}
		std::cout << std::endl;
		if (row % 3 == 2 && row < 8) { // Разделители между блоками 3x3
			std::cout << "------+-------+------" << std::endl;
		}
	}
	
}

int Sudoku::RandomNumber() {
	return rand() % 9;
}
void Sudoku::RemoveRandomNumber(SudokuGrid& Sgrid) {
	const int count = 30;
	int cnt = 0;
	int row = 0;
	int col = 0;
	while (cnt != count) {
		row = RandomNumber();
		col = RandomNumber();
		Sgrid.grid[row][col] = 0;
		++cnt;
	}
}
bool Sudoku::CheckGrid(SudokuGrid& Sgrid) {
	for (int row = 0; row < 9; ++row) {
		for (int col = 0; col < 9; ++col) {
			if (Sgrid.grid[row][col] != 0) { // если ячейка заполнена
				int num = Sgrid.grid[row][col];
				Sgrid.grid[row][col] = 0; // временно очищаем для проверки
				if (!CanPlace(Sgrid, row, col, num)) {
					Sgrid.grid[row][col] = num; // возвращаем значение
					return false; // поле некорректно
				}
				Sgrid.grid[row][col] = num; // возвращаем значение
			}
		}
	}
	return true; // поле корректно
}
void Sudoku::SaveGrid(SudokuGrid& Sgrid) {
	std::string filename = "Savefile.txt";
	std::ofstream file(filename);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			file << Sgrid.grid[i][j] << " ";
		}
		file << std::endl;
	}
	std::cout << "Судоку сохранён в файл " << filename << std::endl;
}

void Sudoku::LoadGrid(SudokuGrid& Sgrid) {
	std::string filename = "Loadfile.txt";
	std::ifstream file(filename);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			file >> Sgrid.grid[i][j];
		}
	}
}
bool Sudoku::GenerateSudoku(SudokuGrid& Sgrid) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			Sgrid.grid[i][j] = 0;
		}
	}
	srand(time(NULL)); // инициализация генератора случайных чисел
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

			// Перемешиваем вектор «вручную» с помощью rand()
				for (int i = 0; i < nums.size(); ++i) {
					// Выбираем случайный индекс для обмена
					int randomIndex = rand() % nums.size();
					// Меняем местами элементы
					std::swap(nums[i], nums[randomIndex]);
				}
			bool placed = false;
			for (int num : nums) {
				if (CanPlace(Sgrid, row, col, num)) {
					Sgrid.grid[row][col] = num;
					placed = true;
					break;
				}
			}

			if (!placed) {
				// Если число не удалось разместить - откатываемся
				return false;
			}
		}
	}
	return true;
}
void Sudoku::print(SudokuGrid& grid) {
	Sudoku solver;
	std::string input2;
	bool flag2 = true;
	int choice = 0;
	std::cout << "Куда вывести решённое судоку?" << std::endl;
	std::cout << "1 - в консоль" << std::endl;
	std::cout << "2 - в файл" << std::endl;
	std::cout << "3 - в консоль и файл" << std::endl;
	while (flag2) {
		try {
			getline(std::cin, input2);
			choice = stoi(input2);
			flag2 = false;
		}
		catch (std::invalid_argument) {
			std::cerr << "Ошибка ввода. Попробуйте снова!" << std::endl;
		}
		if (choice > 0 && choice < 4) {
			flag2 = false;
		}
		else {
			std::cerr << "Ошибка ввода. Попробуйте снова!" << std::endl;
			continue;
		}
	}
	if (choice == 1) {
		std::cout << "Решённое судоку:" << std::endl;
		solver.PrintGrid(grid);
	}
	else if (choice == 2) {
		solver.SaveGrid(grid);
	}
	else if (choice == 3) {
		solver.SaveGrid(grid);
		std::cout << "Решённое судоку:" << std::endl;
		solver.PrintGrid(grid);
	}
	
}
