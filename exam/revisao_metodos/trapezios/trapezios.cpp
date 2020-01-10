#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
  return exp(1.5 * x);
}

double trapezios(double a, double b, double h) {
  double n = (b - a) / h;
  double s = f(a) + f(b);
  for (unsigned int i = 1; i < n; i++) {
    s += 2.0 * f(a + i * h);
  }
  s *= (h/2.0);

  cout << "h = " << h << "   " << "s = " << s << endl << endl;

  return s;
}

int main() {
  double a = 1, b = 1.5, h = 0.125;
  double s = trapezios(a,b,h);
  double sl = trapezios(a, b, h/2.0);
  double sll = trapezios(a, b, h/4.0);
  double qc = (sl - s) / (sll - sl);
  double e = (sll - sl);

  cout << " Qc = " << qc << endl << "e = " << e << endl;

  system("pause");
  return 0;
}