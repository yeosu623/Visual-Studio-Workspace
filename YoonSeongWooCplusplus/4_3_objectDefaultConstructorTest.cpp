//#include <iostream>
//using namespace std;
//
//class Point {
//private:
//	int x;
//	int y;
//public:
//	Point() {
//		x = 0;
//		y = 0;
//	}
//	Point(const int& xpos, const int& ypos) {
//		x = xpos;
//		y = ypos;
//	}
//	void printPoint() {
//		cout << x << ' ' << y << ' ';
//	}
//};
//
//class Rectangle {
//private:
//	Point upLeft;
//	Point lowRight;
//public:
//	Rectangle(const int &x1, const int &y1, const int &x2, const int &y2) 
//		:upLeft(x1, y1), lowRight(x2, y2)
//	{
//
//	}
//	void printRectangle() {
//		upLeft.printPoint();
//		lowRight.printPoint();
//		cout << endl;
//	}
//};
//
//int main() {
//	Rectangle rec(1, 1, 10, 10);
//	rec.printRectangle();
//
//	return 0;
//}