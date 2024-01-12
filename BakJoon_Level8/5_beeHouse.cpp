#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b = 1; // 거리
	int c = 1; // 벌집의 길이
	int d = 1; // 최대 번호
	while (a > d)
	{
		d += (c * 6);
		c++;
		b++;
	}

	cout << b;

	return 0;
}