//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//class Person
//{
//private:
//	char* name;
//	int age;
//public:
//	Person(char* myname, int myage)
//	{
//		int len = strlen(myname) + 1;
//		name = new char[len];
//		strcpy(name, myname);
//		age = myage;
//	}
//	void ShowPersonInfo() const
//	{
//		cout << "�̸�: " << name << endl;
//		cout << "����: " << age << endl;
//	}
//	~Person()
//	{
//		delete[] name;
//		cout << "called destructor!" << endl;
//	}
//};
//
//int main()
//{
//	char name[10] = "Jung";
//	Person* p = new Person(name, 10);
//	p->ShowPersonInfo();
//
//	delete p;
//
//	return 0;
//}