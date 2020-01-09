#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) {
  return 3.0 * pow(x, 2) - x * y + 11.0 * y + pow(y, 2) - 8.0 * x;
}

double dfx(double x, double y) {
  return -y + 6.0 * x - 8.0;
}

double dfy(double x, double y) {
  return 2.0 * y - x + 11.0;
}



void gradiente(double x0, double y0, double lambda, int n) {
  double x = x0, y = y0, xn, yn;

  cout << 0 << "     " << "f( " << x << ", " << y << " ) = " << f(x, y) << endl;
  cout << "gradiente: " << dfx(x, y) << "    " << dfy(x, y) << endl;

  for (unsigned int i = 0; i < n; i++) {

    xn = x - lambda * dfx(x,y);
    yn = y - lambda * dfy(x,y);

    if (f(xn,yn)<f(x,y)) {
      x = xn;
      y = yn;
      lambda *= 2.0;
    }
    else {
      lambda /= 2.0;
    }

    cout << i+1 << "     " << "f( " << x << ", " << y << " ) = " << f(x, y) << endl;
    cout << "gradiente: " << dfx(x, y) << "    " << dfy(x, y) << endl;
  }

}

int main() {
  double x0 = 2, y0 = 2, lambda = 0.5;
  gradiente(x0, y0,lambda,1);
  system("pause");
  return 0;
}