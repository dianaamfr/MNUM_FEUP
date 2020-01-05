#include <iostream>
#include <cmath>

using namespace std;

double a = 1.2;
double b = 1.0;

double J(double x, double y) {
  return 4*x*y-1;
}

double h(double x, double y) {
  return -(pow(y,2) + 2 * (-y + pow(x,2) - a) * y - x - b) / J(x,y);
}

double k(double x, double y) {
  return -(2 * x * (pow(y,2) - x - b) - y + pow(x,2) - a) / J(x, y);
}

void newton(double x0, double y0, int n) {
  double xn = x0, yn = y0, xnant;
  cout << "xn" << "          " << "yn" << "          " << endl;

  for (unsigned int i = 0; i <= n; i++) {
    cout << xn << "          " << yn << "          " << endl;
    xnant = xn;
    xn = xn + h(xn,yn);
    yn = yn + k(xnant,yn);
  }
}

int main() {
  double x0 = 1, y0 = 1;

  newton(x0, y0, 2);

  system("pause");
  return 0;
}

