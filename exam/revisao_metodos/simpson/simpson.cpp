#include <cmath>
#include <iostream>

using namespace std;


double f(double x, double c) {
  return exp(c*x);
}

double simpson(double a , double b, double h, double c) {
  double s = f(a,c) + f(b,c);
  int n = abs(b - a) / h;

  for (unsigned int i = 1; i < n; i++) {
    if(i % 2 == 0)
      s += 2.0 * f(a +i*h,c);
    else
      s += 4.0 * f(a + i * h,c);
  }
  
  s *= (h / 3.0);
  cout << "h = " << h << endl;
  cout << "s = "<< s << endl;
  cout << endl;

  return s;
}

int main() {

  double a = 1, b = 1.5, c = 1.5, h = 0.125;

  double s = simpson(a,b,h,c);
  double sl = simpson(a, b, h/2.0, c);
  double sll = simpson(a, b, h/4.0, c);

  double qc = (sl - s) / (sll - sl);
  double e = (sll - sl) / 15.0;

  cout << "Qc = " << qc << endl;
  cout << "E'' = " << e << endl;

  system("pause");
  return 0;
}