#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<vector<int>> A(5, vector<int>(5));
vector<vector<int>> temp(5, vector<int>(5));
vector<vector<int>> temp2(5, vector<int>(5));

vector<vector<int>> matrixMul(vector<vector<int>>& a, vector<vector<int>> b)
{
	vector<vector<int>> result(5, vector<int>(5, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
				result[i][j] += a[i][k] * b[k][j] % 1000;

			result[i][j] %= 1000;
		}

	return result;
}

vector<vector<int>> recursion(uint64_t b)
{
	if (b == 1) return A;

	temp = recursion(b / 2);
	if (b % 2 == 1) return matrixMul(temp2 = matrixMul(temp, temp), A);
	else return matrixMul(temp, temp);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	uint64_t b;
	cin >> n;
	cin >> b;

	int input;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			A[i][j] = input % 1000;
		}

	vector<vector<int>> answer = recursion(b);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}