#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == y1 && x2 == y2 && r1 == r2) cout << -1 << '\n';
		
		int x = abs(x2 - x1), y = abs(y2 - y1);
		// case 1 : 두 터렛이 서로의 범위 내에 없을 때
		if (pow(x, 2) + pow(y, 2) > pow(r1, 2) && pow(x, 2) + pow(y, 2) > pow(r2, 2)) {
			if (pow(x, 2) + pow(y, 2) <  pow(r1 + r2, 2)) cout << 2 << '\n';
			if (pow(x, 2) + pow(y, 2) == pow(r1 + r2, 2)) cout << 1 << '\n';
			if (pow(x, 2) + pow(y, 2) >  pow(r1 + r2, 2)) cout << 0 << '\n';
		}
		// case2 : 하나의 터렛이 다른 터렛의 범위 내에 있을 때
		else {
			if (r1 > r2) {
				if (pow(x, 2) + pow(y, 2) + pow(r2, 2) >  pow(r1, 2)) cout << 2 << '\n';
				if (pow(x, 2) + pow(y, 2) + pow(r2, 2) == pow(r1, 2)) cout << 1 << '\n';
				if (pow(x, 2) + pow(y, 2) + pow(r2, 2) <  pow(r1, 2)) cout << 0 << '\n';
			}
			else {
				if (pow(x, 2) + pow(y, 2) + pow(r1, 2) >  pow(r2, 2)) cout << 2 << '\n';
				if (pow(x, 2) + pow(y, 2) + pow(r1, 2) == pow(r2, 2)) cout << 1 << '\n';
				if (pow(x, 2) + pow(y, 2) + pow(r1, 2) <  pow(r2, 2)) cout << 0 << '\n';
			}
		}
	}

	return 0;
}