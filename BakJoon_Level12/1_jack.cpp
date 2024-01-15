#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	int c;
	vector<int> v;
	while (a--)
	{
		cin >> c;
		v.push_back(c);
	}

	int d;
	int max = 0;
	for (int i = 0; i < v.size() - 2; i++)
	{
		for (int j = i+1; j < v.size() - 1; j++)
		{
			for (int k = j+1; k < v.size(); k++)
			{
				d = v[i] + v[j] + v[k];
				if (d > max && d <= b) max = d;
			}
		}
	}

	cout << max;
	return 0;
}