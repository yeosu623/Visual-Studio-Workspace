#include <iostream>
using namespace std;

void printStar(int i, int j, int a)
{
	if ((i / a) % 3 == 1 && (j / a) % 3 == 1)
		cout << ' ';
	else
	{
		if (a / 3 == 0)
			cout << '*';
		else
			printStar(i, j, a / 3);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
			printStar(i, j, a);
		cout << '\n';
	}

	return 0;
}