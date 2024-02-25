#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<int, vector<int>, cmp> pq;
	pq.push(1);
	pq.push(5);
	pq.push(3);
	pq.push(2);
	pq.push(4);

	for (int i = 0; i < 5; i++)
	{
		cout << pq.top() << ' ';
		pq.pop();
	}

	return 0;
}
