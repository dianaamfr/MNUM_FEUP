#include <cmath>
#include <iostream>

using namespace std;

double f(double x, double y) {
  if (x == 0.0 && y == 0.0) return 1.1;
  else if (x == 0.0 && y == 1.0) return 2.1;
  else if (x == 0.0 && y == 2.0)return 7.3;

  else if (x == 1.0 && y == 0.0) return 1.4;
  else if (x == 1.0 && y == 1.0) return 3.1;
  else if (x == 1.0 && y == 2.0) return 1.5;

  else if (x == 2.0 && y == 0.0) return 7.7;
  else if (x == 2.0 && y == 1.0) return 2.2;
  else if (x == 2.0 && y == 2.0) return 1.2;
  else cout << "ERROR\n";
}

double trapezios(double a, double b, double A, double B) {
  double hx = (A-a)/2.0;
  double hy = (B-b)/2.0;

  double s = f(a, b) + f(A, B) + f(a, B) + f(A, b);
  s += 2 * (f(a,b+hy) + f(A,b+hy) + f(a+hx,b) + f(a+hx,B));
  s += 4 * f(a+hx, b+hy);

  s *= hx * hy / 4.0;

  return s;
}

double simpson(double a, double b, double A, double B) {
  double hx = (A - a) / 2.0;
  double hy = (B - b) / 2.0;

  double s = f(a,b) + f(a,B) + f(A,b) + f(A,B);
  s += 4 * (f(a+hx,b) + f(a+hx,B)+ f(a,b+hy) + f(A,b+hy));
  s += 16 * f(a+hx,b+hy);

  s *= hx * hy / 9.0;

  return s;
}

int main() {
  double a = 0, b = 0, A = 2, B = 2;

  cout << "Trapezios -> " << trapezios(a,b,A,B)<< endl;
  cout << "Simpson -> " << simpson(a, b, A, B) << endl;

  system("pause");
  return 0;
}