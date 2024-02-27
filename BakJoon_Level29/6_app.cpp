#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int cache[10001][100];
bool cmp(pair<int, int>& v1, pair<int, int>& v2)
{
	if (v1.first == v2.first) return v1.second < v2.second;
	return v1.first < v2.first;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int input;
	vector<pair<int, int>> v(N); // c and m
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		v[i].second = input;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		v[i].first = input;
	}
	sort(v.begin(), v.end(), cmp);

	/* KnapSack Algorithm */
	// y : total c
	// x : (c, m)
	int answer = INT_MAX;
	for (int i = 0; i < 10001; i++) // x = 0
	{
		if (i < v[0].first) cache[i][0] = 0;
		else cache[i][0] = v[0].second;

		if (cache[i][0] >= M)
			answer = min(answer, i);
	}
	for (int x = 1; x < v.size(); x++) // x = 1 ~
		for (int y = 0; y < 10001; y++) // y = 0 ~ 10000
		{
			int& c = v[x].first;
			int& m = v[x].second;

			if (y < c) cache[y][x] = cache[y][x - 1];
			else cache[y][x] = max(cache[y - c][x - 1] + m, cache[y][x - 1]);

			if (cache[y][x] >= M)
				answer = min(answer, y);
		}

	cout << answer;
	return 0;
}