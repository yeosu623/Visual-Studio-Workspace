#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool descending(int a, int b)
{
	return a > b;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b;
	vector<vector<int>> v(a, vector<int>(a));
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			cin >> b;
			v[i][j] = b;
		}
	}

	vector<int> x;
	vector<int> y;
	vector<int> z;
	for (int i = 0; i < a/2; i++)
		z.push_back(1);
	for (int i = 0; i < a/2; i++)
		z.push_back(0);
	vector<int> w(a / 2);
	w[0] = 1;
	w[1] = 1;
	int sum;
	int total1 = 0;
	int total2 = 0;
	int total;
	int min = INT_MAX;
	
	pair<int, int> p = { 0, 0 };
	do
	{
		x.clear();
		y.clear();
		sort(w.begin(), w.end(), descending);
		sort(z.begin(), z.end(), descending);
		p.first = 0;
		p.second = 0;
		total1 = 0;
		total2 = 0;

		for (int i = 0; i < a; i++)
		{
			if (z[i]) x.push_back(i);
			else y.push_back(i);
		}

		// x�� ���Ͽ�
		do
		{
			for (int i = 0; i < x.size(); i++)
			{
				if (w[i])
				{
					if (p.first == 0) p.first = x[i];
					else p.second = x[i];
				}
			}

			sum = v[p.first][p.second] + v[p.second][p.first];
			total1 += sum;
		} while (prev_permutation(w.begin(), w.end()));

		// y�� ���Ͽ�
		sort(w.begin(), w.end(), descending);
		do
		{
			for (int i = 0; i < y.size(); i++)
			{
				if (w[i])
				{
					if (p.first == 0) p.first = y[i];
					else p.second = y[i];
				}
			}

			sum = v[p.first][p.second] + v[p.second][p.first];
			total2 += sum;
		} while (prev_permutation(w.begin(), w.end()));

		total = abs(total1 - total2);
		if (min > total) min = total;

	} while (prev_permutation(z.begin(), z.end()));

	cout << total;
	return 0;
}