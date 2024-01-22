#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<double>> cache(5, vector<double>(5, -1));

int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << cache[i][j] << ' ';
		}
		cout << '\n';
	}
}