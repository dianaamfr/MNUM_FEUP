#include <iostream>
#include <cmath>

using namespace std;

double B = (sqrt(5.0)-1.0)/2.0;
double A = pow(B, 2);

double f(double x) {
  return 5.0 * cos(x) - sin(x);
}

void aurea(double x1, double x2, int n) {
  double x3, x4;

  for (unsigned int i = 0; i < n; i++) {

    x3 = x1 + A * (x2-x1);
    x4 = x1 + B * (x2 - x1);

    cout << "x1 = " << x1 << "         " << "f(x1) = " << f(x1) << endl;
    cout << "x2 = " << x2 << "         " << "f(x2) = " << f(x2) << endl;
    cout << "x3 = " << x3 << "         " << "f(x3) = " << f(x3) << endl;
    cout << "x4 = " << x4 << "         " << "f(x4) = " << f(x4) << endl;
    cout << endl;

    if (f(x3) < f(x4)) {
      x2 = x4;
    }
    else {
      x1 = x3;
    }
  }
  cout << endl;
}



int main() {
  double x1 = 2, x2 = 4;
  aurea(x1,x2,3);

  system("pause");
  return 0;
}