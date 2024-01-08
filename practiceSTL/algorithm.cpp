//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool cmp(const int a, const int b) { return a > b; }
//
//int main()
//{
//	int arr1[10] = { 10, 5, 4, 2, 6, 1, 8, 9, 9, 3 };
//	vector<int> arr2 = { 10, 5, 4, 2, 6, 1, 8, 9, 9, 3 };
//	int n = 10;
//
//	/* sorting */
//	sort(arr2.begin(), arr2.end());
//	//sort(arr1, arr1 + n, cmp);
//	sort(arr1, arr1 + n);
//
//	cout << "sort" << endl << "arr1 : ";
//	for (int i = 0; i < 10; i++)
//		cout << arr1[i] << ' ';
//
//	cout << endl << "arr2 : ";
//	for (int i = 0; i < 10; i++)
//		cout << arr2[i] << ' ';
//
//	cout << endl << endl;
//
//	/* lower_bound */
//	int idx = lower_bound(arr1, arr1 + n, 5) - arr1;
//	cout << "lower_bound(5) = " << idx << endl;
//
//	/* upper_bound */
//	idx = upper_bound(arr2.begin(), arr2.end(), 5) - arr2.begin();
//	cout << "upper_bound(5) = " << idx << endl;
//
//	/* max_element */
//	cout << "max_element = " << *max_element(arr1, arr1 + n) << endl;
//
//	/* min_element */
//	cout << "min_element = " << *min_element(arr2.begin(), arr2.end()) << endl << endl;
//
//	/* unique */
//	arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
//
//	for (const int& n : arr2)
//		cout << n << ' ';
//	cout << endl << endl;
//
//	/* next_permutation */
//	vector<int> arr3 = { 1, 2, 3 };
//
//	do
//	{
//		for (const auto& n : arr3) cout << n << ' ';
//		cout << endl;
//	} while (next_permutation(arr3.begin(), arr3.end()));
//}