#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

int counting[1000001];
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int input;
	vector<int> v;
	memset(counting, 0, sizeof(counting));
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		counting[input]++;
		v.push_back(input);
	}

	vector<int> answer(n, -1);
	stack<pair<int, int>> st; // idx, value
	for (int i = 0; i < v.size(); i++)
	{
		while (!st.empty())
		{
			int& idx = st.top().first;
			int& value = st.top().second;
			if (counting[value] < counting[v[i]])
			{
				answer[idx] = v[i];
				st.pop();
			}
			else break;
		}
		st.push({ i, v[i] });
	}

	for (int i = 0; i < n; i++)
		cout << answer[i] << ' ';
	return 0;
}