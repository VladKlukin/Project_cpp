#include <vector>
#include <iostream>
#include <string>
struct SudokuGrid {
	std::vector<std::vector<int>> grid;
	SudokuGrid() : grid(9, std::vector<int>(9, 0)) {}//конструктор, который заполняет поле 0
};
struct Sudoku {
	auto GetRow(SudokuGrid &Sgrid, int row);
	auto GetCol(SudokuGrid& Sgrid, int col);
	auto getBlock(SudokuGrid& Sgrid, int block);
	bool CanPlace(SudokuGrid& Sgrid, int row, int col, int num);
	bool SolveSudoku(SudokuGrid& Sgrid);
	void PrintGrid(SudokuGrid& Sgrid);
	void RemoveRandomNumber(SudokuGrid& Sgrid);
	int RandomNumber();
	bool CheckGrid(SudokuGrid& Sgrid);
	void SaveGrid(SudokuGrid& Sgrid);
	void LoadGrid(SudokuGrid& Sgrid);
	bool GenerateSudoku(SudokuGrid& Sgrid);
	void print(SudokuGrid& Sgrid);
};
