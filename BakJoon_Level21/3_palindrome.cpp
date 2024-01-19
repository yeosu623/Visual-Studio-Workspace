#include <iostream>
#include <string>
using namespace std;

int cnt = 0;

int recursion(string& s, int l, int r) {
    cnt++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(string& s) {
    return recursion(s, 0, s.length() - 1);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a;
    cin >> a;

    string s;
    for (int i = 0; i < a; i++)
    {
        cin >> s;

        cout << isPalindrome(s) << ' ' << cnt << '\n';
        cnt = 0;
    }
}