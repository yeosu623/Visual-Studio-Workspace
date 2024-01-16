#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, aa;
	int b, bb;

	cin >> a >> aa;
	cin >> b >> bb;

	// 분모를 공통으로
	int temp = aa;
	a *= bb;
	aa *= bb;
	b *= temp;
	bb *= temp;

	// 더한다.
	int c, cc;
	c = a + b;
	cc = aa;

	// 기약분수로 만든다.
	int min = (c < cc) ? c : cc;
	for (int i = 2; i <= min; i++)
	{
		if (c % i == 0)
			if (cc % i == 0)
			{
				c /= i;
				cc /= i;

				min = (c < cc) ? c : cc;
				i = 1;
			}
	}

	cout << c << ' ' << cc;
	return 0;
}