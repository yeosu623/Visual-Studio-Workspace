#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int l, r;
	int input;
	uint64_t answer = -1;
	uint64_t h, w, area;
	vector<int> v;

	while (1)
	{
		cin >> n;
		if (n == 0) break;

		v.clear();
		while (n--)
		{
			cin >> input;
			v.push_back(input);
		}

		for (int i = 0; i < v.size(); i++)
		{
			h = v[i];
			w = 1;
			// ¿ÞÂÊ Å½»ö
			l = i - 1;
			while (l >= 0 && v[l] >= v[i])
			{
				w++;
				l--;
			}
			// ¿À¸¥ÂÊ Å½»ö
			r = i + 1;
			while (r < v.size() && v[r] >= v[i])
			{
				w++;
				r++;
			}

			area = h * w;
			if (area > answer) answer = area;
		}

		cout << answer << '\n';
	}

	return 0;
}