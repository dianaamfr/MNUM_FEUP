#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) {
  return sin(y) + pow(y, 2) / 4 + cos(x) + pow(x, 2) / 4 - 1;
}

double fx(double x) {
  return x - (x / 2.0 - sin(x)) / (1 / 2.0 - cos(x));
}

double fy(double y) {
  return y - (y / 2.0 + cos(y)) / (1 / 2.0 - sin(y));
}

void quadrica(double x0, double y0, double nIter) {
  double x = x0, y = y0;

  for (unsigned int i = 0; i < nIter; i++) {
    x = fx(x);
    y = fy(y);
  }

  cout << " x = " << x << endl;
  cout << " y = " << y << endl;
  cout << " f(x,y) = " << f(x, y) << endl;
}

int main() {
  double x0 = 0, y0 = 0;

  quadrica(x0, y0, 4);
  system("pause");
  return 0;
}