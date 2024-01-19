#include <iostream>
#include <vector>
using namespace std;

void cantoringAlong(vector<char>& v, int a, int size, int start)
{
	if (a == 0) return;

	int l = start + (size / 3);
	int r = start + (size / 3 * 2);
	for (int i = l; i < r; i++)
		v[i] = ' ';

	cantoringAlong(v, a - 1, size / 3, start);
	cantoringAlong(v, a - 1, size / 3, r);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	vector<char> v;
	while (cin >> a)
	{
		int len = 1;

		for (int i = 0; i < a; i++)
			len *= 3;
		for (int i = 0; i < len; i++)
			v.push_back('-');
		cantoringAlong(v, a, v.size(), 0);

		for (const auto& n : v)
			cout << n;
		cout << '\n';

		v.clear();
	}

	return 0;
}