#include <iostream>
#include <cmath>
using namespace std;

double a = 0;

double f(double x) {
  return pow(x-a,2)+pow(x,4);
}

void aurea(double x1, double x2, double precision) {
  double x3, x4;
  double B = (sqrt(5) - 1) / 2.0;
  double A = B * B;

  do {
    x3 = x1 + A*(x2-x1);
    x4 = x1 + B*(x2-x1);

    if (f(x3)<f(x4)) {
      x2 = x4;
    }
    else {
      x1 = x3;
    }
  } while (abs(x2 - x1) > precision);

  if (x1 == x3) {
    cout << " x = " << x3 << "       " << "y = " << f(x3) << endl;
    cout << " x = " << x4 << "       " << "y = " << f(x4) << endl;
    cout << " x = " << x2 << "       " << "y = " << f(x2) << endl;
  }
  else {
    cout << " x = " << x1 << "       " << "y = " << f(x1) << endl;
    cout << " x = " << x3 << "       " << "y = " << f(x3) << endl;
    cout << " x = " << x4 << "       " << "y = " << f(x4) << endl;
  }
}

int main() {
  aurea(-1.0,1.0,pow(10,-3));
  system("pause");
  return 0;
}