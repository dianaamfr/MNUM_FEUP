#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) {
  return -1.1*x*y+12.0*y+7.0*pow(x,2)-8.0*x;
}

double dfx(double x, double y) {
  return -1.1 * y + 14.0 * x - 8.0;
}

double dfy(double x, double y) {
  return -1.1 * x + 12.0;
}

void gradiente(double x0, double y0, double lambda, int n) {
  double x = x0, y = y0, xn, yn;

  for (unsigned int i = 0; i < n; i ++) {
    
    xn = x - lambda * dfx(x,y);
    yn = y - lambda * dfy(x,y);

    if (f(xn,yn)>f(x,y)) {
      lambda /= 2.0;
    }
    else {
      lambda *= 2.0;
      x = xn;
      y = yn;
    }

    cout << "iteracao " << i + 1 << "     f( " << x << ", " << y << " ) = " << f(x, y) << endl;
  }
  cout << endl;
}

int main() {
  double x0 = 3;
  double y0 = 1;
  double lambda = 0.1;
  gradiente(x0,y0,lambda,1);
  system("pause");
  return 0;
}