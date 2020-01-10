#include <iostream>
#include <cmath>
using namespace std;

double a = 2.0, b = 2.0;

double f(double t, double x) {
  return sin(a * x) + sin(b * t);
}

double rk4(double t0, double x0, double h, int n){
  double x = x0, t = t0;
  double d1, d2, d3, d4;
  cout << "t = " << t0 << "    " << "x = " << x0 << endl;
  for (unsigned int i = 0; i < n; i++) {
    d1 = h*f(t,x);
    d2 = h*f(t+h/2.0,x+d1/2.0);
    d3 = h * f(t + h / 2.0, x + d2 / 2.0);
    d4 = h * f(t + h, x + d3);

    x += d1 / 6.0 + d2 / 3.0 + d3 / 3.0 + d4 / 6.0;
    t += h;

    cout << "t = " << t << "    " << "x = " << x << endl;
  }
  cout << endl;

  return x;
}

int main() {
  double x0 = 1, t0 = 1, h = 0.5;
  double x = rk4(t0,x0,h,1);
  double xl = rk4(t0, x0, h/2.0, 1*2.0);
  double xll = rk4(t0, x0, h/4.0, 1*4.0);

  cout << " Qc = " << (xl - x) / (xll - xl) << endl;

  system("pause");
  return 0;
}
