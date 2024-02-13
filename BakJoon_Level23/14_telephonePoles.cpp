#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

	int n;
	cin >> n;

	int input1, input2;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		cin >> input1 >> input2;
		v.push_back({ input1, input2 });
	}

	sort(v.begin(), v.end(), cmp);

	int cache[100];
	cache[0] = 1;
	for (int i = 1; i < n; i++)
	{
		int max_length = 1;
		for (int j = 0; j < i; j++)
			if (v[j].second < v[i].second)
				max_length = max(max_length, cache[j] + 1);

		cache[i] = max_length;
	}

	int answer = n - *max_element(cache, cache + n);
	cout << answer;

	return 0;
}