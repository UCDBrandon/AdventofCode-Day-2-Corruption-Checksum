#include <iostream>
#include <ostream>
#include <fstream>

using namespace std;

int main() {
	ifstream input;
	int x;
	int counter = 0;
	const int col = 16;
	const int row = 16;
	int temp[row * col];
	int store[row][col];
	int max[row];
	int min[row];
	int difference[row];
	int total = 0;
	input.open("input.txt");
	if (!input)
	{
		cout << "FAIL";
	}
	while (input >> x)
	{
		temp[counter] = x;
		counter++;
	}
	counter = 0;
	for (int i = 0; i < row; i++)
	{
		max[i] = temp[counter];
		min[i] = temp[counter];
 		for (int j = 0; j < col; j++)
		{
			store[i][j] = temp[counter];
			if (max[i] < store[i][j])
			{
				max[i] = store[i][j];
			}
			if (min[i] > store[i][j])
			{
				min[i] = store[i][j];
			}
			counter++;
		}
		difference[i] = max[i] - min[i];
	}
	for (int i = 0; i < row; i++)
	{
		total = total + difference[i];
	}
	cout << total << endl;
	return 0;
}