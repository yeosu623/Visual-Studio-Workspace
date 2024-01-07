//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int num = 0;
//	try
//	{
//		while (1)
//		{
//			num++;
//			cout << num << "번째 할당 시도" << endl;
//			new int[10000][10000];
//		}
//	}
//	catch (bad_alloc& bad)
//	{
//		cout << bad.what() << endl;
//	}
//
//	return 0;
//}