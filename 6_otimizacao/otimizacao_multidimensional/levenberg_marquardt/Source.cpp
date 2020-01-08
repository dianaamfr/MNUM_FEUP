#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Exercise 1 - not done yet
//double  f(double x, double y) { return sin(y)+pow(y,2)/4 + cos(x)+pow(x,2)/4-1; }
//double dfx(double x, double y) { return x / 2 - sin(x);}
//double dfy(double x, double y) { return cos(y) + y / 2; }
//double  invHxdelta(double x, double y) { return (x / 2 - sin(x)) / (1 / 2 - cos(x)); }
//double  invHydelta(double x, double y) { return (cos(y) + y / 2) / (1 / 2 - sin(y)); }

//Exercise 2
double  f(double x, double y) {return pow(x + 1, 2) + pow(y - 4, 2); }
double dfx(double x, double y) { return 2 * ( x + 1 ); }
double dfy(double x, double y) { return 2 * ( y - 4 ); }
double  invHxdelta(double x, double y) { return x+1;}
double  invHydelta(double x, double y) { return y-4; }



void levenberg_marquardt(double x0, double y0, double lambda, const double error, int n) {

  double x = x0, y = y0, xn, yn, xant, yant;
  unsigned int counter = 0;
  bool not_valid = true;

  do {
    if (counter >= n) break;

    xant = x;
    yant = y;
    xn = x - (invHxdelta(x, y)) - (lambda * dfx(x, y));
    yn = y - (invHydelta(x, y)) - (lambda * dfy(x, y));

    if (f(xn, yn) < f(x, y)) {
      lambda /= 2;
      x = xn;
      y = yn;
      not_valid = false;
    }
    else {
      lambda *= 2;
      not_valid = true;
    }
    cout << setw(2) << counter << "     " << "f( " << x << " , " << y << " ) = " << f(x, y) << endl;
    counter++;
  } while ((abs(xn - xant) > error) || (abs(yn - yant) > error) || not_valid);
}


int main() {
  double x0, y0, prec=pow(10,-3);
  //Exercise 1 - not done yet
  /*x0=1;
  y0=1;
  levenberg_marquardt(x0, y0, 0.1, prec, 22);*/

  //Exercise 2
  x0=0;
  y0=0;
  levenberg_marquardt(x0, y0, 0.1, prec,4);

  return 0;
}