//#include <iostream>
//using namespace std;
//
//void One();
//void Two();
//void Three();
//
//void One()
//{
//	Two();
//	cout << "One called" << endl;
//}
//
//void Two()
//{
//	try
//	{
//		Three();
//	}
//	catch (int expn)
//	{
//		cout << "���� �ڵ� :  " << expn << endl;
//	}
//	cout << "Two called" << endl;
//}
//
//void Three()
//{
//	throw (-1);
//	cout << "Three called" << endl;
//}
//
//int main()
//{
//	try
//	{
//		One();
//	}
//	catch (int expn)
//	{
//		cout << "���� �ڵ� : " << expn << endl;
//	}
//
//	return 0;
//}