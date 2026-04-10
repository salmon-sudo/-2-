#include <iostream>
#include <clocale>

using namespace std;

class Point {
protected:
	int x;
	int y;

public:
	Point() : x(0), y(0) {
		cout << "конструктор без параметор Point: " << "x: " << x << " y: " << y << '\n';
	}
	Point(int a, int b) : x(a), y(b) {
		cout << "конструктор с параметрами Point: " << "x: " << x << " y: " << y << '\n';
	}
	Point(const Point& other) : x(other.x), y(other.y) {
		cout << "конструктор копирования Point: " << "x: " << x << " y: " << y << '\n';
	}
	~Point() {
		cout << "деструктор Point: точки удалены " << x << ", " << y << '\n';
	}
	void show() {
		cout << "текущие координаты (" << x << ", " << y << ")" << '\n';
	}
};

class ColorPoint : public Point {
private:
	int color;

public:
	ColorPoint(int a, int b, int c) : Point(a, b), color(c) {
		x += 1;
		y += 1;
		cout << "конструктор использующий переменные Point x + 1 и y + 1 и свою переменную color: " << x << " " << y << " " << color << '\n';
	}
	ColorPoint(const ColorPoint& other) : Point(other), color(other.color) {
		cout << "конструктор копирования ColorPoint" << '\n';
	}
	~ColorPoint() {
		cout << "деструктор ColorPoint: удаление цвет " << color << '\n';
	}
	void show() {
		Point::show();
		cout << "цвет точки:" << color << '\n';
	}
};

class Line {
private:
	Point p1;
	Point* p2;

public:
	Line(int x1, int y1, int x2, int y2) : p1(x1, y1) {
		p2 = new Point(x2, y2);
	}
	~Line() {
		cout << "Деструктор Line начало" << '\n';
		delete p2;
		cout << "Деструктор Line завершение" << '\n';
	}
	void show() {
		cout << "Линия состоит из:" << '\n';
		cout << "Точка 1 (объект): "; p1.show();
		cout << "Точка 2 (указатель): "; p2->show();
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "\n Композиция Line \n\n";
	Line myLine(10, 10, 20, 20);
	myLine.show();

	return 0;
}
