#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b;
	vector<int> v(20000001);

	for (int i = 0; i < a; i++)
	{
		cin >> b;
		v[b + 10000000]++;
	}

	int c;
	cin >> c;

	int d;
	for (int i = 0; i < c; i++)
	{
		cin >> d;
		cout << v[d + 10000000] << ' ';
	}

	return 0;
}