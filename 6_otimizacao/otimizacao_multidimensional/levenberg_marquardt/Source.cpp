#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Exercise 1 - not done yet
/*double  f(double x, double y) { return sin(y)+pow(y,2)/4 + cos(x)+pow(x,2)/4-1; }
double dfx(double x, double y) { return 0;}
double dfy(double x, double y) { return 0; }
double  Hxdelta(double x, double y) { return 0; }
double  Hydelta(double x, double y) { return 0; }*/

//Exercise 2
double  f(double x, double y) {return pow(x + 1, 2) + pow(y - 4, 2); }
double dfx(double x, double y) { return 2 * ( x + 1 ); }
double dfy(double x, double y) { return 2 * ( y - 4 ); }
double  Hxdelta(double x, double y) { return x+1;}
double  Hydelta(double x, double y) { return y-4; }



void levenberg_marquardt(double x0, double y0, double lambda, const double error, int n) {

  double xn = x0, yn = y0;
  unsigned int counter = 0;

  do {
    x0 = xn;
    y0 = yn;

    xn = x0 - (Hxdelta(x0, y0)) + (lambda * dfx(x0, y0));
    yn = y0 - (Hydelta(x0, y0)) + (lambda * dfy(x0, y0));

    if (f(xn, yn) < f(x0, y0)) {
      lambda /= 2;
    }
    else if (f(xn, yn) > f(x0, y0)) {
      lambda *= 2;
    }

    counter++;

    cout << setw(2) << counter << "     " << "f( " << xn << " , " << yn << " ) = " << f(xn, yn) << endl;
  } while ((abs(xn - x0) > error || abs(yn - y0) > error) && counter < n);

}


int main() {
  double x0, y0, prec=pow(10,-3);
  //Exercise 1 - not done yet
  //x0=1;
  //y0=1;
  //levenberg_marquardt(x0, y0, 0.1, prec, 22);

  //Exercise 2
  x0=0;
  y0=0;
  levenberg_marquardt(x0, y0, 0.1, prec,4);

  return 0;
}