#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return false;

	return true;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int num = 1000000;
	vector<bool> v(num + 1, true);

	// 2. 소수 판별
	for (int i = 2; i * i <= num; i++) {
		if (v[i]) {
			for (int k = i * i; k <= num; k += i) {
				v[k] = false;
			}
		}
	}
	v[0] = false;
	v[1] = false;

	int b;
	for (int i = 0; i < a; i++)
	{
		cin >> b;

		int count = 0;
		for (int i = 2; i <= b / 2; i++)
			if (v[i] && v[b - i])
				count++;

		cout << count << '\n';
	}

	return 0;
}