#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int A[101][101];
int B[101][101];
int C[101][101];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int input;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> input;
			A[i][j] = input;
		}

	int k;
	cin >> m >> k;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++)
		{
			cin >> input;
			B[i][j] = input;
		}

	// 행렬 계산 결과 : n * k 행렬 C
	memset(C, 0, sizeof(C));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			for (int l = 0; l < m; l++)
				C[i][j] += A[i][l] * B[l][j];

	// 출력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << C[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}