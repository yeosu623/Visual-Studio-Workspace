#include <iostream>
#include <vector>
using namespace std;

int arr[9][9], L;
vector<pair<int, int>> v;

bool isend = false;
//value 사용 할 수 있는지 체크하는 함수
//리턴 값 true면 사용가능
bool check(int x, int y, int value) {
	for (int i = 0; i < 9; i++) {
		if (arr[i][y] == value) return false;
		if (arr[x][i] == value) return false;
	}
	//3x3 칸 내에 value 이미 존재하는지 탐색
	int part_x = x / 3;
	int part_y = y / 3;
	part_x *= 3;
	part_y *= 3;
	for (int i = part_x; i < part_x + 3; i++) {
		for (int j = part_y; j < part_y + 3; j++) {
			if (arr[i][j] == value) return false;
		}
	}
	return true;
}

void DFS(int cur) {
	if (isend == true) return;
	if (cur == L) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		isend = true;
	}
	else {
		int nx = v[cur].first;
		int ny = v[cur].second;
		for (int i = 1; i <= 9; i++) {
			if (check(nx, ny, i)) {
				arr[nx][ny] = i;
				DFS(cur + 1);
				//위에 DFS가 정답이 아닐 수도 있으니 초기화하고 돌아줘야한다.
				arr[nx][ny] = 0;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}
	L = v.size();
	DFS(0);
}