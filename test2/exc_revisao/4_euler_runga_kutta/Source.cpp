#include <iostream>
#include <cmath>

using namespace std;

double f(double t, double y) {
  return 4 * exp(0.8 * t) - 0.5 * y;
}

double euler(double t0, double y0, double tf, double h){
  double t, y=y0;
  for (t = t0; t < tf; t += h) {
    y += h*f(t,y);
  }

  return y;
}

double rk2(double t0, double y0, double tf, double h) {
  double y = y0, t;
  for (t = t0; t < tf; t += h) {
    y += h * f(t+h/2, y+(h/2)*f(t,y));
  }

  return y;
}

int main() {

  cout << "(a) Euler\n";
  double y = euler(0,2,4,1);
  cout << "y = " << y << endl;
  cout << endl << endl;

  cout << "(b) RK2\n";
  y = rk2(0, 2, 4, 1);
  cout << "y = " << y << endl;
  cout << endl << endl;

  cout << "(c)\n";
  cout << "Euler (h=1, h'= 0.5, h''=0.25)\n";
  double s = euler(0, 2, 4, 1);
  double sl = euler(0, 2, 4, 0.5);
  double sll = euler(0, 2, 4, 0.25);
  double qc = (sl - s) / (sll - sl);
  cout << "Qc = " << qc << endl;
  cout << "Qc aproximadamente igual a 2? Sim -> passo adequado\n";
  double e = (sll - sl);
  cout << "E = " << e << endl;
  cout << endl << endl;

  cout << "RK2 (h=1, h'= 0.5, h''=0.25)\n";
  s = rk2(0, 2, 4, 1);
  sl= rk2(0, 2, 4, 0.5);
  sll = rk2(0, 2, 4, 0.25);
  qc = (sl - s) / (sll - sl);
  cout << "Qc = " << qc << endl;
  cout << "Qc aproximadamente igual a 4? Nao -> passo nao adequado\n";
  e = (sll - sl)/3;
  cout << "E = " << e << endl;
  cout << endl << endl;

  cout << "(d)\n";
  cout << "RK2 (h=1/2, h'= 1/4, h''=1/8)\n";
  s = rk2(0, 2, 3.99999, 1/2.0);
  sl = rk2(0, 2, 3.99999, 1/4.0);
  sll = rk2(0, 2, 3.99999, 1/8.0);
  qc = (sl - s) / (sll - sl);
  cout << "Qc = " << qc << endl;
  cout << "Qc aproximadamente igual a 4? Sim -> passo adequado\n";
  e = (sll - sl) / 3;
  cout << "E = " << e << endl;
  cout << endl << endl;

  system("pause");
  return 0;
}