#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	cin >> x;

	int stick[] = {64, 32, 16, 8, 4, 2, 1};
	int length = 0;
	int answer = 0;
	for (const auto& n : stick)
	{
		if (length <= x)
		{
			length += x;
			answer++;
		}
		if (length == x) break;
	}

	cout << answer;
	return 0;
}