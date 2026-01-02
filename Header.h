#include <vector>
#include <iostream>
#include <string>
using namespace std;
struct SudokuGrid {
	vector<vector<int>> grid;
	SudokuGrid() : grid(9, vector<int>(9, 0)) {}//конструктор, который заполняет поле 0
};
struct Sudoku {
private:	
public:
	auto GetRow(SudokuGrid &Sgrid, int row);
	auto GetCol(SudokuGrid& Sgrid, int col);
	auto getBlock(SudokuGrid& Sgrid, int block);
};
