#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int input;
	vector<int> v;
	v.push_back(0);
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	int answer = 0;
	vector<int> sum(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + v[i];
		answer += sum[i];
	}

	cout << answer;

	return 0;
}