#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<pair<string, string>> v;
	v.push_back({ "a", "aaa" });
	v.push_back({ "b", "bbb" });
	v.push_back({ "c", "ccc" });

	string s = "ccc";

	int idx = find_if(v.begin(), v.end(),
		[&s](const pair<string, string>& elem) {return elem.second == s;})
		- v.begin();

	cout << idx;

}