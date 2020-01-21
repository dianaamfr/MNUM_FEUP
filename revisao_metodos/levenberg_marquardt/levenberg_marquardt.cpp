#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) {
  return sin(y)+pow(y,2)/4.0+cos(x)+pow(x,2)/4.0-1;
}

double dfx(double x, double y) {
  return x / 2.0 - sin(x);
}

double dfy(double x, double y) {
  return cos(y) + y / 2.0;
}

double invHgradx(double x, double y) {
  return (x / 2.0 - sin(x)) / (1 / 2.0 - cos(x));
}

double invHgrady(double x, double y) {
  return (cos(y) + y / 2.0) / (1 / 2.0 - sin(y));
}

void levenberg(double x0, double y0, double lambda, int n) {
  double x = x0, y = y0, xn, yn;

  for (unsigned int i = 0; i <= n; i++) {
    xn = x - invHgradx(x, y) - lambda * dfx(x, y);
    yn = y - invHgrady(x, y) - lambda * dfy(x, y);

    if (f(xn,yn) > f(x,y)) 
      lambda *= 2.0;
    else 
      lambda /= 2.0;
    
    
    x = xn;
    y = yn;

    cout << "iteracao " << i << "     f( " << x << ", " << y << " ) = " << f(x, y) << endl;
  }
  cout << endl;
}


int main() {
  double x0 = 1;
  double y0 = 1;
  double lambda = 0.1;


  levenberg(x0,y0,lambda,13);
  system("pause");
  return 0;
}