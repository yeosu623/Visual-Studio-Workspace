#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2) {
	return v1[1] < v2[1];
}

int minIdx(vector<vector<int>>& v, int start, int end) {
	int idx = -1;
	int minWeight = 999999;
	for (int i = start; i < end; i++) {
		if (minWeight > v[i][3]) {
			minWeight = v[i][3];
			idx = i;
		}
	}

	return idx;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int input_a;
	int input_h;
	int input_w;
	vector<vector<int>> v;
	for (int i = 0; i < n; i++) {
		cin >> input_a >> input_h >> input_w;
		
		vector<int> temp;
		temp.push_back(i + 1);
		temp.push_back(input_a);
		temp.push_back(input_h);
		temp.push_back(input_w);

		v.push_back(temp);
	}

	int answer = -1;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) {
		int idx = minIdx(v, 0, i);
		int weight;
		int height;
		int sum = 0;
		
		while (idx != -1) {

		}
	}
}