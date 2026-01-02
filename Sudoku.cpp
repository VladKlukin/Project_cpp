#include <iostream>
#include <string>
#include <vector>
#include "Header.h"
#include <ctime>
using namespace std;
auto Sudoku::GetRow(SudokuGrid& Sgrid, int row) {
	vector <int> result;
	for (int col = 0; col < 9; ++col) {
		result.push_back(Sgrid.grid[row][col]);
	}
	return result;
}
auto Sudoku::GetCol(SudokuGrid& Sgrid, int col) {
	vector <int> result;
	for (int row = 0; row < 9; ++row) {
		result.push_back(Sgrid.grid[row][col]);
	}
	return result;
}
auto Sudoku::getBlock(SudokuGrid& Sgrid, int block) {
	exit(1);
}