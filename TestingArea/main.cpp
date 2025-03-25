#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <deque>
#include <list>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	list<int> li;
	for (int i = 0; i < n; i++) li.push_back(i + 1);

	auto cursor = li.begin();

	cout << "<";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k - 1; j++) {
			if (cursor == li.end()) cursor = li.begin();
			cursor++;
			if (cursor == li.end()) cursor = li.begin();
		}
		
		if (i != n - 1) cout << *cursor << ", ";
		else cout << *cursor;

		cursor = li.erase(cursor);
	}
	cout << ">";
} 