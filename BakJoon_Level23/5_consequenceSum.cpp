#include <iostream>
#include <climits>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int input;
	int maxSum = INT_MIN;
	int currentSum = 0;
	for (int i = 0; i < a; i++)
	{
		cin >> input;

		currentSum += input;
		if (currentSum > maxSum) maxSum = currentSum;
		if (currentSum < 0) currentSum = 0;
	}

	cout << maxSum;
	return 0;
}