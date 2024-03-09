#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2)
{
	if (v1[1] == v2[1]) return v1[0] > v2[0];
	return v1[1] < v2[1];
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int input;
	vector<vector<int>> data(0, vector<int>(4)); // w, h, l ,r
	vector<vector<int>> order(0, vector<int>(2)); // i, h
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		data.push_back({ 1, input, i - 1, i + 1 });
		order.push_back({ i, input });
	}
	data[data.size() - 1][3] = -1;
	sort(order.begin(), order.end(), cmp);

	int l, r, i;
	int hl, hr;
	uint64_t w, h;
	uint64_t area;
	uint64_t answer = 0;
	while (!order.empty())
	{
		i = order.back()[0];
		h = order.back()[1];
		order.pop_back();

		w = data[i][0];
		area = w * h;
		if (area > answer) answer = area;
		if (order.empty()) break;

		if (data[i][2] == -1) // right
		{
			data[data[i][3]][0] += data[i][0];
			data[data[i][3]][2] = data[i][2];
		}
		else if (data[i][3] == -1) // left
		{
			data[data[i][2]][0] += data[i][0];
			data[data[i][2]][3] = data[i][3];
		}
		else
		{
			if (data[data[i][2]][1] >= data[data[i][3]][1]) // left
			{
				data[data[i][2]][0] += data[i][0];
				data[data[i][2]][3] = data[i][3];
			}
			else // right
			{
				data[data[i][3]][0] += data[i][0];
				data[data[i][3]][2] = data[i][2];
			}
		}
	}

	cout << answer << '\n';

	return 0;
}