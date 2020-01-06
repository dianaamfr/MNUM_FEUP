#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
  return pow(2 * x + 1, 2) - 5 * cos(10 * x);
}

void aurea_minimo(double x1, double x2, double precision) {
  double B = (sqrt(5) - 1) / 2;
  double A = pow(B, 2);

  cout << "Aurea minimo: " << endl;

  double x3, x4;

  while (abs(x2 - x1) > precision) {
    x3 = x1 + A * (x2 - x1);
    x4 = x1 + B * (x2 - x1);
    
    if (f(x3) < f(x4))  //minimo em [x1,x4]
      x2 = x4;
    else  // minimo em [x3,x2]
      x1 = x3;
  }

  cout << "x1 = " << x1 << "  " << "f(x1) = " << f(x1) << endl;
  cout << "x2 = " << x2 << "  " << "f(x2) = " << f(x2) << endl;
  cout << "x3 = " << x3 << "  " << "f(x3) = " << f(x3) << endl;
  cout << "x4 = " << x4 << "  " << "f(x4) = " << f(x4) << endl;
}

void aurea_maximo(double x1, double x2, double precision) {
  double B = (sqrt(5) - 1.0) / 2.0;
  double A = pow(B, 2);

  cout << "Aurea maximo: " << endl;

  double x3, x4;

  while (abs(x2 - x1) > precision) {
    x3 = x1 + A * (x2 - x1);
    x4 = x1 + B * (x2 - x1);

    if (f(x3) > f(x4))  //maximo em [x1,x4]
      x2 = x4;
    else  // maximo em [x3,x2]
      x1 = x3;
  }

  cout << "x1 = " << x1 << "  " << "f(x1) = " << f(x1) << endl;
  cout << "x2 = " << x2 << "  " << "f(x2) = " << f(x2) << endl;
  cout << "x3 = " << x3 << "  " << "f(x3) = " << f(x3) << endl;
  cout << "x4 = " << x4 << "  " << "f(x4) = " << f(x4) << endl;
}

int main() {
  double x1 = -1.0, x2 = 0.0, precision = 0.01;

  aurea_minimo(x1, x2, precision);
  cout << endl;
  aurea_maximo(x1,x2,precision);

  system("pause");
  return 0;
}