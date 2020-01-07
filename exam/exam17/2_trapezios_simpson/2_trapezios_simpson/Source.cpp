#include <iostream>
#include <cmath>

using namespace std;

double k = 2.5;

double f(double x) {
  return sqrt(1 + pow((k * exp(k*x)),2));
}

double trapezios(double a, double b, double h) {
  int n = (b - a) / h;
  double s = f(a)+f(b);
  
  for (unsigned int i = 1; i < n; i++) {
    s += 2 * f(a + i * h);
  }


  return s*h/2;
}

double simpson(double a, double b, double h) {
  int n = (b - a) / h;
  double s = f(a) + f(b);

  for (unsigned int i = 1; i < n; i++) {
    if (i % 2 == 0)
      s += 2 * f(a + i * h);
    else
      s += 4 * f(a + i * h);
  }
  return s*h/3;
}

int main() {
  double a = 0;
  double b = 1;
  double h = 0.125;

  cout << "Trapezios\n";
  double s = trapezios(a,b,h);
  cout << "h = " << h << "   " << "s = " << s << endl;
  h /= 2;
  double sl = trapezios(a, b, h);
  cout << "h = " << h << "   " << "s = " << sl << endl;
  h /= 2;
  double sll = trapezios(a, b, h);
  cout << "h = " << h << "   " << "s = " << sll << endl;
  double qc = (sl - s) / (sll - sl);
  cout << "qc = " << qc <<  endl;
  double e = (sll - sl) / 3;
  cout << "e = " << e << endl;

  h = 0.125;
  cout << "\nSimpson\n";
  s = simpson(a,b,h);
  cout << "h = " << h << "   " << "s = " << s << endl;
  h /= 2;
  sl = simpson(a, b, h);
  cout << "h = " << h << "   " << "s = " << sl << endl;
  h /= 2;
  sll = simpson(a, b, h);
  cout << "h = " << h << "   " << "s = " << sll << endl;
  h /= 2;
  qc = (sl - s) / (sll - sl);
  cout << "qc = " << qc << endl;
  e = (sll - sl) / 15;
  cout << "e = " << e << endl;

  system("pause");
  return 0;
}