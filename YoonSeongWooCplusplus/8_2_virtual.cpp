//#include <iostream>
//using namespace std;
//
//class First
//{
//public:
//	virtual void MyFunc() {	cout << "FirstFunc" << endl; }
//};
//
//class Second : public First
//{
//public:
//	virtual void MyFunc() { cout << "SecondFunc" << endl; }
//};
//
//class Third : public Second
//{
//public:
//	virtual void MyFunc() { cout << "ThirdFunc" << endl; }
//};
//
//int main()
//{
//	Third* tptr = new Third();
//	Second* sptr = new Second();
//	First* fptr = sptr;
//
//	tptr->MyFunc();
//	sptr->MyFunc();
//	fptr->MyFunc();
//
//	delete tptr;
//	return 0;
//}