#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b = 1; // �Ÿ�
	int c = 1; // ������ ����
	int d = 1; // �ִ� ��ȣ
	while (a > d)
	{
		d += (c * 6);
		c++;
		b++;
	}

	cout << b;

	return 0;
}