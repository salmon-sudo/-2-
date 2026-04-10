#include <iostream>
#include <clocale>
using namespace std;

class Point {
protected:
    int x, y;
public:
    Point() : x(0), y(0) { cout << "конструктор без параметор Point: " << x << " " << y << '\n'; }
    Point(int a, int b) : x(a), y(b) { cout << "конструктор с параметрами Point: " << x << " " << y << '\n'; }
    Point(const Point& other) : x(other.x), y(other.y) { cout << "конструктор копирования Point: " << x << " " << y << '\n'; }
    ~Point() { cout << "деструктор Point: точки удалены " << x << ", " << y << '\n'; }
    void show() { cout << "текущие координаты (" << x << ", " << y << ")" << '\n'; }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Point p1;
    Point p2(1, 2);
    Point p3 = p2;
    p3.show();
    return 0;
}
