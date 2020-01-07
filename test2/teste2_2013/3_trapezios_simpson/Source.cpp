#include <iostream>
#include <cmath>
using namespace std;

double a = 0;
double b = 1;
double k = 1.5;

double f(double x) {
  return sqrt(1+pow(exp(k*x) * k,2));
}

double trapezios(double a, double b, double h) {
  double s = f(a) + f(b);
  int n = (b - a) / h;
  for (int i = 1; i < n; i++) {
    s += 2*f(a + i*h);
  }
  return s*(h/2);
}

double simpson(double a, double b, double h) {
  double s = f(a) + f(b);
  int n = (b - a) / h;
  for (int i = 1; i < n; i++) {
    if(i%2 == 0)
      s += 2 * f(a + i * h);
    else
      s += 4 * f(a + i * h);
  }
  return s * (h / 3);
}

int main() {

  double s = trapezios(0,1,0.25);
  double sl = trapezios(0, 1, 0.125);
  double sll = trapezios(0, 1, 0.0625);


  cout << "Trapezios: \n";
  cout << "h = 0.25 -> " << s << endl;
  cout << "h = 0.125 -> " << sl << endl;
  cout << "h = 0.0625 -> " << sll << endl;
  cout << "Qc = " << (sl - s) / (sll - sl) << endl;
  cout << "E = " << (sll - sl)/3 << endl;

  s = simpson(0, 1, 0.25);
  sl = simpson(0, 1, 0.125);
  sll = simpson(0, 1, 0.0625);

  cout << "\nSimpson: \n";
  cout << "h = 0.25 -> " << s << endl;
  cout << "h = 0.125 -> " << sl << endl;
  cout << "h = 0.0625 -> " << sll << endl;
  double Qc = (sl - s) / (sll - sl);
  cout << "Qc = " << Qc << endl;
  cout << "E = " << (sll - sl) / 15 << endl;

  system("pause");
  return 0;
}