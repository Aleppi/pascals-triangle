#include <iostream>
#include "constants.h"

typedef int (&array7x8)[constants::rows][constants::columns];
array7x8 calculateTriangle();
void printTriangle(int triangle[][constants::columns]);

int main()
{
	/*
	std::cout << "Enter the amount of rows you wish to display: ";
	int rows;
	std::cin >> rows;
	printTriangle(int triangle[rows][rows+1])
	*/
	int triangle[] = calculateTriangle();

	printTriangle(triangle);
	return 0;
}

array7x8 calculateTriangle()
{
	int triangle[constants::rows][constants::columns] = {};
	triangle[0][0] = 1;
	//0 0 1
	//1 0 1
	//2 1
	for (int i = 0; i < constants::rows; ++i)
	{
		for (int j = 0; j < constants::columns; ++j)
		{
			triangle[i + 1][j] = triangle[i][j];
		}
	}
	return triangle;
}

void printTriangle(int triangle[][constants::columns])
{
	for (int i = 0; i < constants::rows; ++i)
	{
		for (int j = 0; j < constants::columns; ++j)
		{
			std::cout << triangle[i][j] << ' ';
			if (j == (constants::columns - 1))
			{
				std::cout << '\n';
			}
		}
	}
}