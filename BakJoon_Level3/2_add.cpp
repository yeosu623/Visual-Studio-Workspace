#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;

	int b, c;
	for (int i = 0; i < a; i++)
	{
		cin >> b >> c;
		cout << b + c << endl;
	}

	return 0;
}