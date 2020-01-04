#include <iostream>
#include <cmath>

using namespace std;

double a = 3, b = 40;

double g(double x) {
  return -x + b * cos(sqrt(x)) + a;
}

double dg(double x){
  return -(2.0 * sqrt(x) + b * sin(sqrt(x))) / (2.0 * sqrt(x));
}

void newton(double x0, int n) {
  double xn = x0, xnant=0;
  cout << "xn" << "          " << "g(xn)" << endl;
  for (unsigned int i = 0; i <= n; i++) {
    cout << xn << "          " << g(xn) << endl;
    xnant = xn;
    xn = xnant - g(xnant)/dg(xnant);
  }
}

int main() {
  double x0 = 1.7;
  newton(x0, 2);
  system("pause");
  return 0;
}