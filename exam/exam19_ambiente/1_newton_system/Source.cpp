#include <iostream>
#include <cmath>

using namespace std;

double f1(double x, double y) {
  return sin(x+y)-exp(x-y);
}

double f2(double x, double y) {
  return cos(x + y) - pow(x, 2) * pow(y, 2);
}

double J(double x, double y) {
  return (cos(y + x) - exp(x - y)) * (-sin(y + x) - 2 * pow(x,2) * y) - (cos(y + x) + exp(x - y)) * (-sin(y + x) - 2 * x * pow(y,2));
}

double h(double x, double y) {
  return ((-sin(y + x) - 2 * pow(x,2) * y) * (sin(y + x) - exp(x - y)) - (cos(y + x) - pow(x,2) * pow(y,2)) * (cos(y + x) + exp(x - y))) / J(x, y);
}

double k(double x, double y) {
  return ((cos(y + x) - pow(x,2) * pow(y,2)) * (cos(y + x) - exp(x - y)) - (-sin(y + x) - 2 * x * pow(y,2)) * (sin(y + x) - exp(x - y))) / J(x, y);
}

void newton(double x0, double y0,int n) {
  double x = x0, y = y0, xant;

  cout << "x = " << x << "      " << "y = " << y << endl;

  for (unsigned int i = 0; i < n; i++) {
    xant = x;
    x -= h(x,y);
    y -= k(xant, y);
    cout << "x = " << x << "      " << "y = " << y << endl;
  }
}

int main() {

  newton(0.5,0.25,2);

  system("pause");
  return 0;
}