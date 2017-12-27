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
	int save[row];
	int total = 0;
	bool mod = false;
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
 		for (int j = 0; j < col; j++)
		{
			store[i][j] = temp[counter];
			counter++;
		}
		for (int j = 0; j < col; j++)
		{
			mod = false;
			for (int z = 0; z < col; z++)
			{
				if (j != z)
				{
					if (store[i][z]%store[i][j] == 0)
					{
						save[i] = store[i][z] / store[i][j];
						mod = true;
						break;
					}
				}
			}
			if (mod)
			{
				break;
			}

		}
	}


	for (int i = 0; i < row; i++)
	{
		total = total + save[i];
	}
	cout << total << endl;
	return 0;
}