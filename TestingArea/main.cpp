#include <iostream>
#include <vector>
using namespace std;

vector<int> Eratos(int n)
{
	vector<int> v;

	if (n <= 1) return v;
	v.resize(n + 1, 1);
	v[0] = 0;
	v[1] = 0;

	for (int i = 2; i * i <= n; i++)
	{
		if (v[i])
		{
			for (int j = i * i; j <= n; j += i)
				v[j] = 0;
		}
	}

	return v;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v = Eratos(100);
	for (int i = 0; i <= 100; i++)
	{
		if (v[i]) cout << i << ' ';
	}
}