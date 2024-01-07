//#include <iostream>
//using namespace std;
//
//template <typename T>
//T Max(T a, T b)
//{
//	return a > b ? a : b;
//}
//
//template <>
//const char* Max<const char*> (const char* a, const char* b)
//{
//	return strlen(a) > strlen(b) ? a : b;
//}
//
//int main()
//{
//	cout << Max(11, 15) << endl;
//	cout << Max('T', 'Q') << endl;
//	cout << Max(3.5, 7.5) << endl;
//	cout << Max<const char*>("Simple", "Best") << endl;
//
//	return 0;
//}