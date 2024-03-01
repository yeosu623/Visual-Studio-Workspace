#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;

		char input1;
		int input2;
		int len = 0, del = 0;
		priority_queue<int> pq1; // 최대값 제거
		priority_queue<int, vector<int>, greater<int>> pq2; // 최소값 제거
		for (int i = 0; i < k; i++)
		{
			cin >> input1;
			cin >> input2;

			if (input1 == 'I')
			{
				pq1.push(input2);
				pq2.push(input2);
				len++;
			}
			else if (input1 == 'D')
			{
				if (pq1.empty() || pq2.empty()) continue;
				else if (input2 == 1) pq1.pop();
				else if (input2 == -1) pq2.pop();
				del++;
					
				if (del == len)
				{
					while (!pq1.empty()) pq1.pop();
					while (!pq2.empty()) pq2.pop();
					len = 0;
					del = 0;
				}
			}
		}

		if (pq1.empty() || pq2.empty()) cout << "EMPTY" << '\n';
		else cout << pq1.top() << ' ' << pq2.top() << '\n';
	}

	return 0;
}