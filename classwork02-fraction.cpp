#include <iostream>
#include <vector>

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

        void Umnozhenie(int t) {
            numerator = numerator * t;
        }

        double calc() {
            double t = numerator/denominator;
            return t;
        }

        int getDenominator {
            return denominator;
        }

        int getNumerator {
            return numerator;
        }

};
















