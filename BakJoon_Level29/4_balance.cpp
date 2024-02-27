#include <iostream>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

set<int> buffer;
void findCombination(vector<int>& v, set<int>& s)
{
	for (int i = 0; i < v.size(); i++)
	{
		buffer.clear();
		buffer.insert(v[i]);
		for (auto iter = s.begin(); iter != s.end(); iter++)
		{
			buffer.insert(*iter + v[i]);
			buffer.insert(abs(*iter - v[i]));
			//buffer.insert(v[i] - (*iter));
		}

		for (auto iter = buffer.begin(); iter != buffer.end(); iter++)
			s.insert(*iter);

		//cout << v[i] << " : ";
		//for (auto iter = s.begin(); iter != s.end(); iter++)
		//	cout << *iter << ' ';
		//cout << '\n';
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int input;
	int w, m; // Weight - Ãß, Marble - ±¸½½
	vector<int> vw;
	vector<int> vm;
	vector<char> answer;
	set<int> weights_combination;

	cin >> w;
	for (int i = 0; i < w; i++)
	{
		cin >> input;
		vw.push_back(input);
	}
	findCombination(vw, weights_combination);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		vm.push_back(input);
	}

	answer.resize(m, 'N');
	vector<int> new_answers;
	while (1)
	{
		new_answers.clear();
		for (int i = 0; i < vm.size(); i++)
		{
			if (weights_combination.find(vm[i]) != weights_combination.end())
			{
				new_answers.push_back(vm[i]);
				vm[i] = -1;
				answer[i] = 'Y';
			}
		}

		if (new_answers.empty()) break;
		//else findCombination(new_answers, weights_combination);
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ' ';
	return 0;
}
