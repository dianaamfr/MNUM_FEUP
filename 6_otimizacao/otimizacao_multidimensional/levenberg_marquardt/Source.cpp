#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Exercise 1

//double  f(double x, double y) { return sin(y) + pow(y, 2) / 4 + cos(x) + pow(x, 2) / 4 - 1; }
//double dfx(double x, double y) { return x / 2 - sin(x); }
//double dfy(double x, double y) { return cos(y) + y / 2; }
//double  invHxdelta(double x, double y) { return (x / 2.0 - sin(x)) / (1 / 2.0 - cos(x)); }
//double  invHydelta(double x, double y) { return (cos(y) + y / 2.0) / (1 / 2.0 - sin(y)); }

//Exercise 2

double  f(double x, double y) { return pow(x + 1, 2) + pow(y - 4, 2); }
double dfx(double x, double y) { return 2 * (x + 1); }
double dfy(double x, double y) { return 2 * (y - 4); }
double  invHxdelta(double x, double y) { return x + 1; }
double  invHydelta(double x, double y) { return y - 4; } 



void levenberg_marquardt(double x0, double y0, double lambda, int n) {

  double x = x0, y = y0, xn = x0, yn = y0;

  for (unsigned int i = 0; i < n; i++) {
    xn = x - invHxdelta(x, y) - lambda * dfx(x, y);
    yn = y - invHydelta(x, y) - lambda * dfy(x, y);

    if (f(xn, yn) < f(x, y))
      lambda /= 2;
    else
      lambda *= 2;

    x = xn;
    y = xn;

    cout << setw(2) << i << "     " << "f( " << x << " , " << y << " ) = " << f(x, y) << endl;
  }
}


int main() {
  double x0, y0;
  //Exercise 1

  /*x0 = 1;
  y0 = 1;
  levenberg_marquardt(x0, y0, 0.1, 14);*/

  //Exercise 2
  
  x0 = 0;
  y0 = 0;
  levenberg_marquardt(x0, y0, 0.1, 4);

  return 0;
}