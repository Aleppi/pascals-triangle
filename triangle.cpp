#include <iostream>
#include <vector>

std::vector<int> calculateTriangle(int num);
void printTriangle(std::vector<int> triangle);

int main()
{
	/*
	std::cout << "Enter the amount of rows you wish to display: ";
	int rows;
	std::cin >> rows;
	printTriangle(int triangle[rows][rows+1])
	*/
	std::cout << "Enter the amount of numbers you want printed: ";
	int num;
	std::cin >> num;
	std::vector<int> triangle = calculateTriangle(num);
	printTriangle(triangle);
	return 0;
}

std::vector<int> calculateTriangle(int num)
{
	std::vector<int> triangle = {1, 1};
	triangle.resize(num);
	for (int i = 2; i < num; ++i) {
		triangle[i] = triangle[i - 1] + triangle[i - 2];
	}
	return triangle;
}

void printTriangle(std::vector<int> triangle)
{
	for (int i = 0; i < triangle.size(); ++i) {
		std::cout << triangle[i] << " ";
	}
}