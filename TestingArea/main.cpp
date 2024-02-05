#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, r, c;
	cin >> n >> r >> c;
	
	int l = pow(2, n);
	int answer = 0;

	while (l != 1)
	{
		// QUARTER °è»ê
		// O|1
		// ---
		// 2|3
		int quarter = 0;
		if (r >= l / 2)
		{
			quarter += 2;
			r /= 2;
		}
		if (c >= l / 2)
		{
			quarter += 1;
			c /= 2;
		}

		// 1 4 16 ...
		// 2^0 2^2 2^4 ...
		answer += pow(2, n * 2);
		cout << l << '/' << answer << '\n';
		l /= 2;
	}

	cout << answer;

	return 0;
}