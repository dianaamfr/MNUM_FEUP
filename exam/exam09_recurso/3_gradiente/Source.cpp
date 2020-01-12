#include <iostream>
#include <cmath>

using namespace std;

double w(double x, double y) {
  return -1.7 * x * y + 12.0 * y + 7.0 * pow(x, 2) - 8.0 * x;
}

double dwx(double x, double y) {
  return -1.7 * y + 14.0 * x - 8.0;
}

double dwy(double x, double y) {
  return 12.0 - 1.7 * x;
}

void gradiente(double x0, double y0, double h, int n) {
  double xn, yn, x = x0, y = y0;

  for (unsigned int i = 0; i < n; i++) {

    xn = x - h * dwx(x,y);
    yn = y - h * dwy(x, y);

    if (w(xn,yn) < w(x,y)) {
      x = xn;
      y = yn;
      h *= 2.0;
    }
    else {
      h /= 2.0;
    }

    cout << " f( " << x << "  ,   " << y << " ) = " << w(x, y) << endl;
  }
}

int main() {
  gradiente(2.4, 4.3, 0.1, 1);
  system("pause");
  return 0;
}