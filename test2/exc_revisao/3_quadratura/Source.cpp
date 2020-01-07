#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
  return 1 -exp(-x);
}

double trapezios(double a, double b, double n) {
  double s = f(a)+f(b);
  double h = (b - a) / n;
  for (unsigned int i = 0; i < n; i++) {
    s += 2 * f(a+i*h);
  }
  return s * (h/2);
}

double simpson(double a, double b, double n) {
  double s = f(a) + f(b);
  double h = (b - a) / n;
  for (unsigned int i = 1; i < n; i++) {
    if(i % 2 == 0)
      s += 2 * f(a+i*h);
    else
      s += 4 * f(a + i * h);
  }
  return s * (h / 3);
}

int main() {
  cout << "(a)Trapezios\n";
  double st = trapezios(0, 4, 4);
  cout << "ST = " << st << endl <<endl;

  cout << "(b)Simpson\n";
  double ss = simpson(0, 4, 4);
  cout << "SS = " << ss << endl<<endl;

  cout << "(c/d)\n";
  double s = trapezios(0, 4, 4);
  double sl = trapezios(0, 4, 4*2);
  double sll = trapezios(0, 4,4*4);
  double qc = (sl - s) / (sll - sl);
  cout << "Trapezios\n";
  cout << "h = 4, h' = 8, h'' = 16" << endl;
  cout << "QcT = " << qc << endl ; 
  cout << "aproximadamente 4 ? Sim - passo adequado!\n";
  cout << "ET = " << (sll - sl) / 3 << endl << endl;

  s = simpson(0, 4,4);
  sl = simpson(0, 4, 4*2);
  sll = simpson(0, 4, 4*4);
  qc = (sl - s) / (sll - sl);
  cout << "Simpson\n";
  cout << "h = 4, h' = 8, h'' = 16" << endl;
  cout << "QcS = " << qc << endl ;
  cout << "aproximadamente 16 ? Nao - passo nao adequado!\n\n";

  s = simpson(0, 4, 4*2);
  sl = simpson(0, 4, 4 * 4);
  sll = simpson(0, 4, 4 * 8);
  qc = (sl - s) / (sll - sl);
  cout << "Simpson\n";
  cout << "h = 8, h' = 16, h'' = 32" << endl;
  cout << "QcS = " << qc << endl;
  cout << "aproximadamente 16 ? Sim - passo adequado!\n\n";
  cout << "ES = " << (sll - sl) / 15 << endl << endl;

  system("pause");
  return 0;
}