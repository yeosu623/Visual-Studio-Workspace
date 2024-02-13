#include <iostream>
#include <climits>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	int input;
	int data[100001];
	int sum[100001];
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		data[i] = input;
		sum[i] = sum[i - 1] + data[i];
	}

	int answer = INT_MIN;
	for (int i = 1; i <= n - k + 1; i++)
		answer = max(answer, sum[i + k - 1] - sum[i - 1]);

	cout << answer;

	return 0;
}