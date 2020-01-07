#include <iostream>
#include <cmath>
using namespace std;

double a = 2.0, b= 2.0;

double f(double t, double x) {
  return sin(a * x)+ sin(b*t);
}

double rk4(double t0, double x0, double h,double tf) {
  double x = x0, t = t0, d1, d2, d3, d4;

  cout << " h = " << h << endl;
  cout << "( n = " << 0 << ") t: " << t << "  " << "x: " << x << endl;

  for (unsigned int i = 0; t < tf ;i++) {
    
    d1 = h * f(t,x);
    d2 = h * f(t + h / 2, x + d1/2);
    d3 = h * f(t + h / 2, x + d2 / 2);
    d4 = h * f(t + h, x + d3);
    x += d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6;
    t += h;
    cout << "( n = " << i + 1 << ") t: " << t << "  " << "x: " << x << endl;
  }

  cout << endl;
  return x;
}

int main() {

  cout << "(a)" << endl;
  double s = rk4(1.0, 1.0, 0.5 / 2.0, 1.5);

  cout << "\n(b)\n";
  double tll = rk4(1.0,1.0,0.5/4.0,1.5);
  double tl = rk4(1.0, 1.0, 0.5/2.0,1.5);
  double t = rk4(1.0, 1.0, 0.5, 1.5);
  cout << "Qc = " << (tl-t)/(tll-tl) << " - não é aproximadamente igual a 16 logo h = 0.5 não é adequado\n";

  cout << "\n(c)\n";
  tll = rk4(1.0, 1.0, 1.5 / 4.0, 1.5);
  tl = rk4(1.0, 1.0, 1.5 / 2.0, 1.5);
  t = rk4(1.0, 1.0, 1.5, 1.5);
  cout << "Qc = " << (tl - t) / (tll - tl) << " - aproximadamente igual a 16 logo h = 1.5 é adequado\n";

  system("pause");
  return 0;
}