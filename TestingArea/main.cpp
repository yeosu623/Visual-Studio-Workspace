#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	vector<int> v(26);
	for (int i = 0; i < s.size(); i++) {
		v[s[i] - 'a']++;
	}

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		v[s[i] - 'a']--;
	}

	int answer = 0;
	for (int i = 0; i < 26; i++) {
		answer += abs(v[i]);
	}

	cout << answer;
}