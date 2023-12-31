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
//
//		strcpy(name, myname);
//		age = myage;
//	}
//
//	Person(const Person& copy) : age(copy.age) // 깊은 복사 생성자
//	{
//		name = new char[strlen(copy.name) + 1];
//		strcpy(name, copy.name);
//	}
//
//	void ShowPersonInfo()
//	{
//		cout << "이름: " << name << endl;
//		cout << "나이: " << age << endl;
//	}
//
//	~Person()
//	{
//		delete[] name;
//		cout << "called destructor!" << endl;
//	}
//};
//
//int main()
//{
//	char name[20] = "Lee dong woo";
//	Person man1(name, 29);
//	Person man2 = man1;
//	man1.ShowPersonInfo();
//	man2.ShowPersonInfo();
//
//	return 0;
//}