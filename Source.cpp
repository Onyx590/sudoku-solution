#include <iostream>

void readSolution(int grid[][9])
{
	std::cout << "Enter a Sudoku puzzle:" << std::endl;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			std::cin >> grid[i][j];
}

bool isValid(int i, int j, const int grid[][9])
{
	for (int column = 0; column < 9; column++)
		if (column != j && grid[i][column] == grid[i][j])
			return false;

	for (int row = 0; row < 9; row++)
		if (row != i && grid[row][j] == grid[i][j])
			return false;

	for (int row = (i / 3) * 3; row < (i / 3) * 3 + 3; row++)
		for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; col++)
			if (row != i && col != j && grid[row][col] == grid[i][j])
				return false;

	return true;
}

bool isValid(const int grid[][9])
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (grid[i][j] < 1 || grid[i][j] > 9 || !isValid(i, j, grid))
				return false;

	return true;
}



int main()
{
	int grid[9][9];
	readSolution(grid);

	std::cout << (isValid(grid) ? "Valid solution" : "Invalid Solution");

	
	 


	return 0;
}