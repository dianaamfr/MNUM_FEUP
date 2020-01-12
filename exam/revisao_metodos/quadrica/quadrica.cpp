#include <cmath>
#include <iostream>

using namespace std;

double f(double x, double y) {
  return sin(y) + pow(y, 2) / 4.0 + cos(x) + pow(x, 2) / 4.0 - 1.0;
}

double fx(double x, double y) {
  return (x / 2.0 - sin(x)) / (1 / 2.0 - cos(x));
}

double fy(double x, double y) {
  return (cos(y) + y / 2.0) / (1 / 2.0 - sin(y));
}

void quadrica(double x0, double y0, int n) {
  double x = x0, y = y0, xant;

  for (unsigned int i = 0; i < n; i++) {
    xant = x;
    x = x - fx(x, y);
    y = y - fy(xant, y);

    cout << "iteracao " << i << "     f( " << x << ", " << y << " ) = " << f(x, y) << endl;
  }
  cout << endl;
}

int main() {

  double x0 = 0, y0 =0;

  quadrica(x0,y0,4);

  system("pause");
  return 0;
}