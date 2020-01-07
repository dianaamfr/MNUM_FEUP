#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) {
  return 1-exp(-x);
}

void simpson_cubatura(double a, double A, double b, double B, double n) {
  double hx = (A - a) / n;
  double hy = (B - b) / n;
  double sum0 = f(a, B) + f(A, B) + f(A, b) + f(a, b);
  double sum1 = f(a+hx,B) + f(a+hx,b) + f(a,b+hy) + f(A,b+hy);
  double sum2 = f(a+hx, a+hy);
  double sum = hx*hy*(sum0 + 4 * sum1 + 16 * sum2)/9.0;

  cout << "(b)Simpson\n";
  cout << "SS = " << sum << endl <<endl;
}

void trapezios_cubatura(double a, double A, double b, double B, double n) {
  double hx = (A - a) / n;
  double hy = (B - b) / n;
  double sum0 = f(a, B) + f(A, B) + f(A, b) + f(a, b);
  double sum1 = f(a + hx, B) + f(a + hx, b) + f(a, b + hy) + f(A, b + hy);
  double sum2 = f(a + hx, a + hy);
  double sum = hx * hy * (sum0 + 2 * sum1 + 4 * sum2) / 4.0;

  cout << "(a)Trapezios\n";
  cout << "ST = " << sum << endl << endl;
}

int main() {
 trapezios_cubatura(-4, 4, -4, 4, 2);
 simpson_cubatura(-4, 4, -4, 4, 2);

 system("pause");
 return 0;
}