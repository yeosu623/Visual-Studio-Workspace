#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v;
	vector<char> w;

	int a;
	cin >> a;

	int b;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		v.push_back(b);
	}

	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
		w.push_back('+');
	cin >> c;
	for (int i = 0; i < c; i++)
		w.push_back('-');
	cin >> c;
	for (int i = 0; i < c; i++)
		w.push_back('*');
	cin >> c;
	for (int i = 0; i < c; i++)
		w.push_back('/');
	sort(w.begin(), w.end());

	int max = INT_MIN;
	int min = INT_MAX;
	vector<int> operand;
	char op;
	do
	{
		operand.clear();
		operand = v;
		for (int i = 0; i < v.size() - 1; i++)
		{
			op = w[i];
			if (op == '+') operand[i + 1] = operand[i] + operand[i + 1];
			else if (op == '-') operand[i + 1] = operand[i] - operand[i + 1];
			else if (op == '*') operand[i + 1] = operand[i] * operand[i + 1];
			else if (op == '/') operand[i + 1] = operand[i] / operand[i + 1];
		}

		if (operand[v.size() - 1] > max) max = operand[v.size() - 1];
		if (operand[v.size() - 1] < min) min = operand[v.size() - 1];
	} while (next_permutation(w.begin(), w.end()));

	cout << max << '\n' << min;

	return 0;
}