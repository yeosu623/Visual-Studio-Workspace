#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int input;
	int data[100001];
	int sum[100001];
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		data[i] = input;
		sum[i] = sum[i - 1] + data[i];
	}

	int start, end;
	while (m--)
	{
		cin >> start >> end;
		cout << sum[end] - sum[start - 1] << '\n';
	}

	return 0;
}