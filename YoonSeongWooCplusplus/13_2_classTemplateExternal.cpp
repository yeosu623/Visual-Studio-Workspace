//#include <iostream>
//using namespace std;
//
//template <typename T>
//class SimpleTemplate
//{
//public:
//	T SimpleFunc(const T& ref);
//};
//
//template <typename T>
//T SimpleTemplate<T>::SimpleFunc(const T& ref)
//{
//	cout << "T SimpleTemplate<T>::SimpleFunc(const T& ref)" << endl;
//
//	return ref;
//}
//
//int main()
//{
//	SimpleTemplate<int> st;
//	const int a = 0;
//	int b;
//	b = st.SimpleFunc(a);
//
//	return 0;
//}