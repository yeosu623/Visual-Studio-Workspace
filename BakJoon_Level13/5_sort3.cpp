#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	vector<int> v(10000);

	int b;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		v[b - 1]++;
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i]; j++)
		{
			cout << i + 1 << '\n';
		}
	}

	return 0;
}