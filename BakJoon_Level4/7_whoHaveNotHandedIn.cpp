#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v(30);

	int a;
	for (int i = 0; i < 28; i++)
	{
		cin >> a;
		v[a - 1] = 1;
	}

	for (int i = 0; i < 30; i++)
	{
		if (v[i] == 0)
			cout << i + 1 << '\n';
	}

	return 0;
}