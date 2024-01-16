#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b;
	vector<int> v;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		v.push_back(b);
	}

	vector<int> w;
	for (int i = 0; i < v.size() - 1; i++)
	{
		w.push_back(v[i + 1] - v[i]);
	}

	int c = gcd(w[0], w[1]);
	for (int i = 2; i < w.size(); i++)
	{
		c = gcd(c, w[i]);
	}

	cout << c;
}