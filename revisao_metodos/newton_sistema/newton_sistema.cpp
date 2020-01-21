#include <cmath>
#include <iostream>
using namespace std;

double a = 2.0, b = 2.0;

double f1(double x, double y) {
  return pow(x,2)-y-a;
}

double f2(double x, double y) {
  return -x+pow(y,2)-b;
}

double J(double x, double y) {
  return 4 * x * y - 1;
}

double h(double x, double y) {
  return (-pow(y,2) + (2 * pow(x,2) - 2 * a) * y - x - b)/ J(x,y);
}

double k(double x, double y) {
  return  (2 * x * pow(y,2) - y - pow(x,2) - 2 * b * x - a) / J(x, y);
}

void newton(double x0, double y0, int n) {
  double x = x0, y = y0, xant;
  cout << " x = " << x << "     " << "y = " << y << endl;
  for (unsigned int i = 0; i < n; i++) {
    xant = x;
    x = x - h(x, y);
    y = y - k(xant, y);

    cout << " x = " << x << "     " << "y = " << y << endl;
  }
}

int main() {
  newton(1.5,0.8,2);
  cout << endl;
  system("pause");
  return 0;
}