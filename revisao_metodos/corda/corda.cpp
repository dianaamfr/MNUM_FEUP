#include <iostream>
#include <cmath>

using namespace std;

double a = 1.0, b = 0.5, c = 0.5;

double f(double x) {
  return a* pow(x,7)+b*x-c;
}

void corda(double x1, double x2, int n) {
  double xn;

  for (unsigned int i = 0; i < n; i++) {
    xn = (f(x2) * x1 - f(x1) * x2) / (f(x2) - f(x1));
    
    cout << "x1 = " << x1 << "     " << "x2 = " << x2 << "      ";
    cout << "xn = " << xn << endl;

    if (f(x1) * f(xn) < 0) x2 = xn;
    else x1 = xn;
  }
}

int main() {
  corda(0.0,0.8,3);
  cout << endl;
  system("pause");
  return 0;
}