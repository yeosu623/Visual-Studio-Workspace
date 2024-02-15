#include <iostream>
#include <cstring>
#define MAX_FACTORIAL 100
using namespace std;

int n1;
int n2;
int n3;
int primes[MAX_FACTORIAL+1];
uint64_t answer;

void countPrimes(int n, char code)
{
	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			if (code == 'a') primes[i]++;
			else if (code == 'm') primes[i]--;
			n /= i;
			i = 1;
		}
	}
}

void factorial(int n, char code)
{
	for (int i = 1; i <= n; i++)
	{
		if (code == 'a') // add primes
			countPrimes(i, code);
		else if (code == 'm') // minus primes
			countPrimes(i, code);
	}
}

void addAnswer()
{
	factorial(n1 + n2 + n3, 'a');
	factorial(n1, 'm');
	factorial(n2, 'm');
	factorial(n3, 'm');

	uint64_t partAnswer = 1;
	for (int i = 0; i < MAX_FACTORIAL + 1; i++)
	{
		while (primes[i])
		{
			primes[i]--;
			partAnswer *= i;
		}
	}
	answer += partAnswer;
}

void recursion(int input)
{
	addAnswer();
	//cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << answer << '\n';
	if (n1 > 1)
	{
		n2 += 1;
		n1 -= 2;
		recursion(input);
	}
	else if (n3 < input / 3)
	{
		n3 += 1;
		n2 = 0;
		n1 = input - n3 * 3;
		recursion(input);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 1; i <= 70; i++)
	{
		n1 = i;
		n2 = 0;
		n3 = 0;
		answer = 0;
		memset(primes, 0, sizeof(primes));

		recursion(i);
		if (i < 10) cout << i << "   = " << answer << '\n';
		else if (i < 100) cout << i << "  = " << answer << '\n';
		else if (i < 1000) cout << i << " = " << answer << '\n';
	}

	return 0;
}