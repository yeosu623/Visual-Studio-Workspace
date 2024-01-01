//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//class Person
//{
//private:
//	int age;
//	char name[50];
//public:
//	Person(int myage, const char* myname) : age(myage)
//	{
//		strcpy(name, myname);
//	}
//	void WhatYourName() const
//	{
//		cout << "My name is " << name << endl;
//	}
//	void HowOldAreYou() const
//	{
//		cout << "I'm " << age << " years old." << endl;
//	}
//};
//
//class UnivStudent : public Person
//{
//private:
//	char major[50];
//public:
//	UnivStudent(const char* myname, int myage, const char* mymajor)
//		:Person(myage, myname)
//	{
//		strcpy(major, mymajor);
//	}
//	void WhoAreYou() const
//	{
//		WhatYourName();
//		HowOldAreYou();
//		cout << "My major is " << major << endl << endl;
//	}
//};
//
//int main()
//{
//	UnivStudent us("Park", 30, "CS");
//	us.WhoAreYou();
//
//	return 0;
//}