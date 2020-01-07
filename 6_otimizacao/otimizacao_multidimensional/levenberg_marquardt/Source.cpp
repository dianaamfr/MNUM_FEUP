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

  double xn = x0, yn = y0, xant, yant;
  unsigned int counter = 0;

  do {
    xant = xn;
    yant = yn;

    xn = xant - (invHxdelta(xant, yant)) + (lambda * dfx(xant, yant));
    yn = yant - (invHydelta(xant, yant)) + (lambda * dfy(xant, yant));

    if (f(xn, yn) < f(xant, yant)) {
      lambda /= 2;
    }
    else if (f(xn, yn) > f(xant, yant)) {
      lambda *= 2;
    }

    counter++;

    cout << setw(2) << counter << "     " << "f( " << xn << " , " << yn << " ) = " << f(xn, yn) << endl;
  } while ((abs(xn - xant) > error || abs(yn - yant) > error) && counter < n);

}


int main() {
  double x0, y0, prec=pow(10,-3);
  //Exercise 1 - not done yet
 /* x0=1;
  y0=1;
  levenberg_marquardt(x0, y0, 0.01, prec, 22);*/

  //Exercise 2
  x0=0;
  y0=0;
  levenberg_marquardt(x0, y0, 0.1, prec,4);

  return 0;
}