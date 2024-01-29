#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int main()
{
	int64_t cache[10][10];
	//float cache[10][10];

	memset(cache, -1, sizeof(cache));
	//fill_n(&cache[0][0], 10 * 10, -1);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << cache[i][j] << ' ';
		cout << '\n';
	}
}