#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	vector<double> v;
	int b;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		v.push_back((double)b);
	}

	double max = *max_element(v.begin(), v.end());

	for (int i = 0; i < a; i++)
	{
		v[i] = v[i] / max * 100;
	}

	double sum = 0.0;
	for (int i = 0; i < a; i++)
	{
		sum += v[i];
	}

	double avg = sum / a;
	cout << avg;

	return 0;
}