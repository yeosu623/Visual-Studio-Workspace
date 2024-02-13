#include <iostream>
#include <cmath>
using namespace std;

int N, M, K;
int B[2001][2001]; int W[2001][2001];
int minimum = 4000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	// N�� M���� �̻����� ���� ����
	// B�迭 : �� ���� ���� �������� �̻����� ����
	// W�迭 : �� ���� ���� �Ͼ���� �̻����� ����
	bool black = false; bool white = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			B[i][j] = black;
			W[i][j] = white;
			black = !black; white = !white;
		}
		if (M % 2 == 0) {
			black = !black; white = !white;
		}
	}

	// 0 : Black, 1 : White
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char tmp;
			cin >> tmp;
			int temp = (tmp == 'B') ? 0 : 1;
			// ���� ��� 0, �ٸ� ��� 1 -> XOR ������ �̿�
			B[i][j] = temp ^ B[i][j];
			W[i][j] = temp ^ W[i][j];

			// 2���� �迭 ������
			B[i][j] = B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1] + B[i][j];;
			W[i][j] = W[i - 1][j] + W[i][j - 1] - W[i - 1][j - 1] + W[i][j];;
		}
	}

	for (int i = 1; i <= N - K + 1; i++) {
		for (int j = 1; j <= M - K + 1; j++) {
			int r = i, c = j, rr = i + K - 1, cc = j + K - 1;
			minimum = min(minimum, B[rr][cc] - B[rr][c - 1] - B[r - 1][cc] + B[r - 1][c - 1]);
			minimum = min(minimum, W[rr][cc] - W[rr][c - 1] - W[r - 1][cc] + W[r - 1][c - 1]);
		}
	}
	printf("%d", minimum);
}