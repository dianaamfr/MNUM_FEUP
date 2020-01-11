#include <iostream>
#include <cmath>

using namespace std;

double f(double u, double v) {
  return u * (u / 2.0 + 1) * pow(v, 3) + (u + 5 / 2.0) * pow(v, 2);
}

double rk4(double u0, double uf, double v0, double h) {
  double u = u0, v = v0;
  double d1, d2, d3, d4;
  int n = (uf - u0) / h;

  for (unsigned int i = 0; i < n; i++) {
    d1 = h * f(u, v);
    d2 = h * f(u + h / 2.0, v + d1 / 2.0);
    d3 = h * f(u + h / 2.0, v + d2 / 2.0);
    d4 = h * f(u + h, v + d3);
    v += d1 / 6.0 + d2 / 3.0 + d3 / 3.0 + d4 / 6.0;
    u += h;
  }


  return v;
}


int main() {

  double s = rk4(1.0, 2.0, 0.1, 0.1);
  double sl = rk4(1.0, 2.0, 0.1, 0.1 / 2.0);
  double sll = rk4(1.0, 2.0, 0.1, 0.1 / 4.0);
  double qc = (sl - s) / (sll - sl);
  double e = (sll - sl) / 15.0;

  cout << "(h = 0.1) s = " << s << endl;
  cout << "(h' = 0.05) s' = " << sl << endl;
  cout << "(h = 0.025) s'' = " << sll << endl;
  cout << " Qc = " << qc << endl;
  cout << " E'' = " << e << endl;


  system("pause");
  return 0;
}