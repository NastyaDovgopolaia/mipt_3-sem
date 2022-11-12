#include <iostream>
#include <cmath>
# include <vector>

using namespace std;

class Point {
    public:
        Point(double x, double y) : x(x), y(y) {}
        Point() : Point(0, 0) {}
        double length0 (const Point& other) const{
            double x1 = this->x;
            double y1 = this->y;
            double x2 = other.x;
            double y2 = other.y;
            double t0 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
            double Length = sqrt(t0);
            return(Length);
        }
        Point operator+ (const Point &other) const {
            return Point ((this->x + other.x), (this->y + other.y));
        }
        Point operator/ (double factor) const {
            return Point ((this->x / factor), (this->y / factor));
        }
        void GetPoint() {
            cout << x << "  " << y << endl;
        }
    private:
        double x;
        double y;
};


class Shape {
    protected:
        vector <Point> storage;
    public:

        virtual double area() const {
            return 0;
        }

        virtual double perimeter() const {
            return 0;
        }

        virtual Point center() const {
            return Point();
        }
};




class Triangle : public Shape {

    public:
        Triangle (vector <Point> storage) {
            for (int i = 0; i < storage.size(); i++) {
                this->storage.push_back(storage[i]);
            }
        }
        double area() const override {
                double a = this->storage[0].length0(this->storage[1]);
                double b = this->storage[1].length0(this->storage[2]);
                double c = this->storage[2].length0(this->storage[0]);
                double p = (a+b+c)/2;
                double Area = sqrt(p*(p-a)*(p-b)*(p-c));
                return(Area);
        }

        double perimeter() const override {
            double Perimeter = this->storage[0].length0(this->storage[1]) + this->storage[1].length0(this->storage[2]) + this->storage[2].length0(this->storage[0]);
            return(Perimeter);
        }

        Point center() const override {
            return (this->storage[0] + this->storage[1] + this->storage[2])/3;
        }
};

class Square : public Shape {

    public:
        Square (vector <Point> storage) {
            for (int i = 0; i < storage.size(); i++) {
                this->storage.push_back(storage[i]);
            }
        }
        double area() const override {
                double a = this->storage[0].length0(this->storage[1]);
                double b = this->storage[1].length0(this->storage[2]);
                double Area = a*b;
                return(Area);
        }

        double perimeter() const override {
            double Perimeter = this->storage[0].length0(this->storage[1]) + this->storage[1].length0(this->storage[2]) + this->storage[2].length0(this->storage[3]) + this->storage[3].length0(this->storage[0]);
            return(Perimeter);
        }

        Point center() const override {
            return (this->storage[0] + this->storage[1] + this->storage[2] + this->storage[3])/4;
        }
};

class Line : public Shape {

    public:
        Line (vector <Point> storage) {
            for (int i = 0; i < storage.size(); i++) {
                this->storage.push_back(storage[i]);
            }
        }
        double area() const override {;
                double Area = 0;
                return(Area);
        }

        double perimeter() const override {
            double Perimeter = this->storage[0].length0(this->storage[1]) + this->storage[1].length0(this->storage[2]);
            return(Perimeter);
        }

        Point center() const override {
            return (this->storage[0] + this->storage[1])/2;
        }
};

int main() {

    Point A(0,0);
    Point B(3,4);
    Point C(3,0);
    vector <Point> Vect2 = {A, B, C};
    Triangle Tr(Vect2);
    cout << Tr.area() << endl;
    Tr.center().GetPoint();
    cout << Tr.perimeter() << endl;




    return 0;
}



