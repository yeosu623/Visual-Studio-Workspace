#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	string s = to_string(a);

	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());

	cout << s;

	return 0;
}