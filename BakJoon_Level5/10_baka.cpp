#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int a;
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		a = (int)(s[i]);

		if ('A' <= a && a <= 'C') sum += 3;
		else if ('D' <= a && a <= 'F') sum += 4;
		else if ('G' <= a && a <= 'I') sum += 5;
		else if ('J' <= a && a <= 'L') sum += 6;
		else if ('M' <= a && a <= 'O') sum += 7;
		else if ('P' <= a && a <= 'S') sum += 8;
		else if ('T' <= a && a <= 'V') sum += 9;
		else if ('W' <= a && a <= 'Z') sum += 10;
	}

	cout << sum;

	return 0;
}