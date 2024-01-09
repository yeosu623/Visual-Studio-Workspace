#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	double a;
	double sum = 0;
	int count = 0;

	for (int i = 0; i < 20; i++)
	{
		cin >> s;
		cin >> a;
		cin >> s;

		if (s.compare("A+") == 0) { sum += (4.5 * a); count += ((int)a); }
		else if (s.compare("A0") == 0) { sum += (4.0 * a); count += ((int)a); }
		else if (s.compare("B+") == 0) { sum += (3.5 * a); count += ((int)a); }
		else if (s.compare("B0") == 0) { sum += (3.0 * a); count += ((int)a); }
		else if (s.compare("C+") == 0) { sum += (2.5 * a); count += ((int)a); }
		else if (s.compare("C0") == 0) { sum += (2.0 * a); count += ((int)a); }
		else if (s.compare("D+") == 0) { sum += (1.5 * a); count += ((int)a); }
		else if (s.compare("D0") == 0) { sum += (1.0 * a); count += ((int)a); }
		else if (s.compare("F") == 0) { sum += (0 * a); count += ((int)a); }
		else if (s.compare("P") == 0) { ; }
	}

	cout << sum / count;

	return 0;
}