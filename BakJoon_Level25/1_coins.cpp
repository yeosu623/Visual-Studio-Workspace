#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	int input;
	int coins[10];
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		coins[i] = input;
	}

	int idx = n - 1;
	int answer = 0;
	while (k)
	{
		int coin = coins[idx];
		if (k / coin > 0)
		{
			k -= coin;
			answer++;
		}
		else idx--;
	}

	cout << answer;

	return 0;
}