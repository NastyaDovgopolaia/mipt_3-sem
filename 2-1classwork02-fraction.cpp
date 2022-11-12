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
    private:
        int numerator;
        int denominator;
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

        void multbynumber(int t) {
            numerator = numerator * t;
        }

        void multbyfrac(const fraction& other) {
            this->numerator = this->numerator*other.numerator;
            this->denominator = this->denominator*other.denominator;
        }

        fraction multbyfracreturn(const fraction& other) const {
            int a1 = this->numerator * other.numerator;
            int a2 = this->denominator*other.denominator;
            fraction a(a1,a2);
            a.fracsimplify();
            return(a);
        }

        void SumFrac(const fraction& other) {
            this->numerator = this->numerator*other.denominator + other.numerator*this->denominator;
            this->denominator = this->denominator*other.denominator;
        }

        fraction SumAndReturn(const fraction& other) const {

            int a1 = this->numerator*other.denominator + other.numerator*this->denominator;
            int a2 = this->denominator*other.denominator;

            fraction a(a1,a2);
            a.fracsimplify();
            return(a);
        }

        void DiffFrac(const fraction& other) {
            this->numerator = this->numerator*other.denominator - other.numerator*this->denominator;
            this->denominator = this->denominator*other.denominator;
        }

        fraction SumAndReturn(const fraction& other) const {

            int a1 = this->numerator*other.denominator - other.numerator*this->denominator;
            int a2 = this->denominator*other.denominator;

            fraction a(a1,a2);
            a.fracsimplify();
            return(a);
        }

        double calc() {
            double t = numerator/denominator;
            return t;
        }

        int getDenominator() {
            return denominator;
        }

        int getNumerator() {
            return numerator;
        }
};















