#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool condition(vector<uint64_t>& v, uint64_t length, uint64_t n)
{
	uint64_t sum = 0;
	for (uint64_t i = 0; i < v.size(); i++)
		sum += v[i] / length;

	if (sum >= n) return true;
	else return false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	uint64_t k, n;
	cin >> k >> n;

	uint64_t input;
	vector<uint64_t> v;
	for (uint64_t i = 0; i < k; i++)
	{
		cin >> input;
		v.push_back(input);
	}

	uint64_t l = 1;
	uint64_t h = *max_element(v.begin(), v.end());
	uint64_t m;
	while (l < h)
	{
		m = (l + h + 1) / 2;

		if (condition(v, m, n)) l = m;
		else h = m - 1;
	}

	cout << l;

	return 0;
}