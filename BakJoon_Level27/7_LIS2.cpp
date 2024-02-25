#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000001] = { 0, };

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N;
    vector<int> v;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    v.push_back(arr[0]);

    for (int i = 1; i < N; i++) {
        if (v.back() < arr[i]) v.push_back(arr[i]);
        else {
            auto it = lower_bound(v.begin(), v.end(), arr[i]);
            v[it - v.begin()] = arr[i];
        }
    }

    cout << v.size();
    return 0;
}