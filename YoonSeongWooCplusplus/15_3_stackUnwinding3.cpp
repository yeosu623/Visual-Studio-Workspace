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
//		cout << "에러 코드 :  " << expn << endl;
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
//		cout << "예외 코드 : " << expn << endl;
//	}
//
//	return 0;
//}