#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v;
	int a, b;
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> a;
		b = a % 42;
		v.push_back(b);

		int flag = 1;
		for (int j = 0; j < v.size() - 1; j++)
		{
			if (v[j] == b) flag = 0;
		}

		if (flag == 1) sum++;
	}

	cout << sum;

	return 0;
}