#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int n, m;
	int answer;
	int priority;
	int input;
	pair<int, char> temp;
	queue<pair<int, char>> que;
	vector<int> priority_count(10, 0); // idx 0�� �̻��

	while (a--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> input;
			if (i == m) que.push({ input, 'O' }); // ��
			else que.push({ input, 'X' }); // �ٸ� ���

			priority_count[input]++;
		}

		answer = 0;
		priority = 9; // 9���� �����ؼ� ���������� �ϰ�

		while (1)
		{
			while (priority_count[priority] == 0)
				priority--;

			temp = que.front();
			que.pop();

			if (temp.first == priority)
			{
				answer++;
				priority_count[priority]--;

				if (temp.second == 'O') break;
			}
			else
			{
				que.push(temp);
			}
		}

		cout << answer << '\n';
		while (!que.empty()) que.pop();
		priority_count.clear();
		priority_count.resize(10, 0);
	}

	return 0;
}