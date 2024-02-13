#include <iostream>
#include <cstring>
using namespace std;

int v[1000001];
uint64_t sum[1000001];
int rest_count[1000]; // 0~999

uint64_t bino(uint64_t n)
{
	if (n < 2) return 0;
	else return n * (n - 1) / 2;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int input;
	int r;
	sum[0] = 0;
	memset(rest_count, 0, sizeof(rest_count));
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		v[i] = input;
		sum[i] = sum[i - 1] + v[i];

		r = sum[i] % m;
		rest_count[r]++;
	}

	uint64_t answer = 0;
	answer += rest_count[0];
	for (int i = 0; i < m; i++)
		answer += bino(rest_count[i]);

	cout << answer;

	return 0;
}