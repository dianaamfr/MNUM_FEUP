#include <cmath>
#include <iostream>

using namespace std;

double a = 1, b = 2;

double f(double t, double x) {
  return sin(a*x) + sin(b*t);
}

double rk4(double x0, double t0,double h, int n) {
  double x = x0, t = t0, d1, d2, d3, d4;
  cout << "t = " << t << "   " << "x = " << x << endl;
  for (unsigned int i = 0; i < n; i++) {
    d1 = h*f(t,x);
    d2 = h* f(t + h/2.0, x+d1/2.0);
    d3 = h* f(t + h / 2.0, x + d2 / 2.0);
    d4 = h* f(t+h, x +d3);
    x += d1 / 6.0 + d2 / 3.0 + d3 / 3.0 + d4 / 6.0;
    t += h;
    cout << "t = " << t << "   " << "x = " << x << endl;
  }
  return x;
}

double rk4_alineab(double t0, double x0, double h, int n) {
  double x = x0, t = t0, d1, d2, d3, d4;
  for (unsigned int i = 0; i < n; i++) {
    d1 = h * f(t, x);
    d2 = h * f(t + h / 2.0, x + d1 / 2.0);
    d3 = h * f(t + h / 2.0, x + d2 / 2.0);
    d4 = h * f(t + h, x + d3);
    x += d1 / 6.0 + d2 / 3.0 + d3 / 3.0 + d4 / 6.0;
    t += h;
  }
  return x;
}

int main() {
  cout << "(a)\n";
  double s = rk4(1.0,1.0,0.5,1);
  cout << endl;
  double sl = rk4(1.0, 1.0, 0.5/2.0, 1*2.0);
  cout << endl;
  double sll = rk4(1.0, 1.0, 0.5 / 4.0, 1 * 4.0);
  

  cout << endl;
  cout << "(b)\n";
  s = rk4_alineab(1.5, 1.0, 0.5, 1);
  sl = rk4_alineab(1.5, 1.0, 0.5 / 2.0, 1 * 2.0);
  sll = rk4_alineab(1.5, 1.0, 0.5 / 4.0, 1 * 4.0);
  double Qc = (sl - s) / (sll - sl);
  cout << "Qc = " << Qc;

  system("pause");
  return 0;
}