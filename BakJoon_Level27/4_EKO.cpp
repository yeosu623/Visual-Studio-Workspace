#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool condition(vector<int>& v, int M, int N, int blade)
{
	uint64_t sum = 0;
	for (int i = 0; i < N; i++)
		if (v[i] > blade) sum += v[i] - blade;

	if (sum >= M) return true;
	else return false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int input;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		v.push_back(input);
	}

	int l = 0;
	int r = *max_element(v.begin(), v.end());
	int m;
	while (l < r)
	{
		m = (l + r + 1) / 2;

		if (condition(v, M, N, m)) l = m;
		else r = m - 1;
	}

	cout << r;

	return 0;
}