#include <iostream>

using namespace std;



int NOD(int n1, int n2)
{
  int div;
  if (n1 == n2)  return n1;
  int d = n1 - n2;
  if (d < 0) {
    d = -d;  div = NOD(n1, d);
  } else
    div = NOD(n2, d);
  return div;
}

class fraction {
    public:
        fraction(int numerator, int denominator) {
            this->numerator = numerator;
            this->denominator = denominator;
        }

        fraction(const fraction& other) {
            this->numerator = other.numerator;
            this->denominator = other.denominator;
        };

        fraction(int numerator) {
            this->numerator = numerator;
            this->denominator = 1;
        }
        fraction& operator += (const fraction& other) {
            this->numerator = this->numerator*other.denominator + other.numerator*this->denominator;
            this->denominator = this->denominator*other.denominator;
            return *this;
        }
        fraction& operator-=(const fraction& other) {
            this->numerator = this->numerator*other.denominator - other.numerator*this->denominator;
            this->denominator = this->denominator*other.denominator;
            return *this;
        }
        fraction& operator*=(const fraction& other) {
            this->numerator = this->numerator*other.numerator;
            this->denominator = this->denominator*other.denominator;
            this->fracsimplify();
            return *this;
        }

        fraction& operator++();
        fraction operator++(int);
        fraction& operator--();
        fraction operator--(int);

        void printfraction() {
            cout << numerator << " / " << denominator << endl;
        }

        void fracreverse() {
            int temp = numerator;
            this->numerator = denominator;
            this->denominator = temp;
        }

        void fracsimplify() {

            int nod = NOD(numerator, denominator);
            numerator = numerator / nod;
            denominator = denominator / nod;
            cout << endl;
        }

        double calc() {
            double t1 = numerator;
            double t2 = denominator;
            double t = t1/t2;
            return t;
        }

        int getDenominator() {
            return denominator;
        }

        int getNumerator() {
            return numerator;
        }
    private:
        int numerator;
        int denominator;
};

int main() {

    fraction a(3,5);
    fraction b(7,2);
    a += b;
    a.printfraction();

}
