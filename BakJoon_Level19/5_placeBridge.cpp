#include <iostream>
using namespace std;

uint64_t factorial(int n)
{
	uint64_t value = 1;
	for (int i = 1; i <= n; i++)
		value *= i;

	return value;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int r, n;
	for (int i = 0; i < a; i++)
	{
		cin >> r >> n;
		
		// nCr (조합) 계산
		// nCr = n! / r! / (n-r)!
		uint64_t value = 1;
		uint64_t div = 1;
		if (r > n - r) // n! / r!
		{
			div = factorial(n - r);
			for (int j = r + 1; j <= n; j++)
			{
				value *= j;
				for(int k = 2; k <= n-r; k++)
					if(value % k == 0)
						if (div % k == 0)
						{
							value /= k;
							div /= k;
							k = 1;
						}
			}
		}
		else // n! / (n-r)!
		{
			div = factorial(r);
			for (int j = n - r + 1; j <= n; j++)
			{
				value *= j;
				for (int k = 2; k <= r; k++)
					if (value % k == 0)
						if (div % k == 0)
						{
							value /= k;
							div /= k;
							k = 1;
						}
			}
		}

		cout << value << '\n';
	}

	return 0;
}