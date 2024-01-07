//#include <iostream>
//using namespace std;
//
//template <typename T>
//class SoSimple
//{
//public:
//	T SimpleFunc(T num)
//	{
//		cout << num << endl;
//		return num;
//	}
//};
//
//template <>
//class SoSimple<int>
//{
//public:
//	int SimpleFunc(int num)
//	{
//		cout << num << " + Specialized SoSimple<int> class." << endl;
//		return num;
//	}
//};
//
//int main()
//{
//	SoSimple<double> ssd;
//	ssd.SimpleFunc(10.1);
//
//	SoSimple<int> ssi;
//	ssi.SimpleFunc(20);
//
//	return 0;
//}