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

	cout << "\n Базовый класс Point \n\n";
	Point p1;
	Point p2(1, 2);
	Point p3 = p2;
	Point* p4 = new Point(5, 5);

	p4->show();
	p3.show();

	cout << "\n Наследование ColorPoint \n\n";
	ColorPoint q1(10, 15, 20);
	q1.show();

	cout << "\n Копирование объектов ColorPoint \n\n";
	ColorPoint cp_orig(1, 2, 3);
	ColorPoint cp_copy = cp_orig;
	cp_copy.show();

	cout << "\n Композиция Line \n\n";
	Line myLine(10, 10, 20, 20);
	myLine.show();

	cout << "\n Копирование объектов \n\n";
	Point objA(10, 10);
	Point objB = objA;

	objA.show();
	objB.show();

	objA = Point(99, 99);
	objA.show();
	objB.show();

	cout << "\n Копирование указателей \n\n";
	Point* ptr1 = new Point(55, 55);
	Point* ptr2 = ptr1;

	ptr1->show();
	ptr2->show();

	*ptr1 = Point(77, 77);
	ptr1->show();
	ptr2->show();

	cout << "\n Указатель базового класса на объект потомка \n\n";
	Point* base_ptr = new ColorPoint(1, 1, 100);
	base_ptr->show();
	delete base_ptr;

	cout << "\n Очистка памяти \n\n";
	delete ptr1;
	delete p4;

	return 0;
}
