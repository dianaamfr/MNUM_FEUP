#include <iostream>
#include <cmath>
using namespace std;

double f(double u, double v) {
  return u*(u / 2.0 + 1.0) * pow(v, 3) + (u + 5.0 / 2.0) * pow(v, 2);
}

double euler(double u0, double v0, double uf,double h) {

  double v = v0;
  double u = u0;

  while(u < uf) {
    v += h * f(u, v);
    u += h;
  }

  cout << "(h = " << h << ") ";
  return v;
}

int main() {
  double s = euler(1, 0.1, 1.8, 0.08);
  double sl = euler(1, 0.1, 1.8, 0.08 / 2.0);
  double sll = euler(1, 0.1, 1.8, 0.08 / 4.0);
  cout << s;
  cout << endl;
  cout << sl;
  cout << endl;
  cout << sll;
  cout << endl;
  cout << "Qc = " << (sl - s) / (sll - sl);
  cout << endl;
  cout << "E = " << (sll - sl);
  cout << endl;

  system("pause");
  return 0;
}