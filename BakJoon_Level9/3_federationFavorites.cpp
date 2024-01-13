#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (1)
	{
		int a;
		cin >> a;
		if (a == -1) break;

		vector<int> v;
		for (int i = 1; i <= sqrt(a); i++)
		{
			if (a % i == 0)
			{
				v.push_back(i);
				v.push_back(a / i);
			}
		}

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()) - 1, v.end());

		int sum = 0;
		for (const auto& n : v)
			sum += n;

		if (sum == a)
		{
			cout << a << " = ";
			for (int i = 0; i < v.size() - 1; i++)
				cout << v[i] << " + ";
			cout << v[v.size() - 1] << '\n';
		}
		else
			cout << a << " is NOT perfect.\n";
	}

	return 0;
}