#include <iostream>
#include <string>

using namespace std;

struct Point {
public:
    unsigned long long const x, y;
    Point(unsigned long long x, unsigned long long y) : x(x), y(y) {}
    Point minx(const Point &rha) const {
        return Point(rha.x < x ? rha.x : x, y);
    }
    Point miny(const Point &rha) const {
        return Point(x, rha.y < y ? rha.y : y);
    }
    Point maxx(const Point &rha) const {
        return Point(rha.x > x ? rha.x : x, y);
    }
    Point maxy(const Point &rha) const {
        return Point(x, rha.y > y ? rha.y : y);
    }
    void print() const {
        cout << '(' << x << " ; "  << y << ')' << endl;
    }
};

class Rectangle {
public:
    Rectangle() : Rectangle(Point(0,0)) {}
    Rectangle(Point const &top) : top(top) {}
    Rectangle operator+(const Rectangle &rha) const {
        Point maxix = this->top.maxx(rha.top);
        Point maxiy = this->top.maxy(rha.top);
        int x0 = maxix.x;
        int y0 = maxiy.y;
        Point top1 = Point(x0, y0);
        Rectangle rectangle1 = Rectangle(top1);
        return(rectangle1);
    }
    Rectangle operator*(const Rectangle &rha) const {
        Point minix = this->top.minx(rha.top);
        Point miniy = this->top.miny(rha.top);
        int x0 = minix.x;
        int y0 = miniy.y;
        Point top1 = Point(x0, y0);
        Rectangle rectangle1 = Rectangle(top1);
        return(rectangle1);
    }
    Point getTop() const {
        return top;
    }
    void print() const {
        top.print();
    }
private:
    Point top;
};

int main() {



}














