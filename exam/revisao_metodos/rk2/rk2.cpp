#include <cmath>
#include <iostream>

using namespace std;

double f(double x, double y) {
  return pow(x, 2) + pow(y, 2);
}

void rk2(double x0, double y0, double xf, double h) {
  double x = x0, y = y0;
  int n = (xf - x0) / h;

  for (unsigned int i = 0; i < n; i++) {
    y += h * f(x + h/2.0, y + (h/2.0) * f(x,y));
    x += h;
  }

  cout << y << endl;

}

int main() {
  double x0 = 0, y0 = 0, xf = 1.39, h= 0.1;
  rk2(x0, y0,xf,h);
  system("pause");
  return 0;
}