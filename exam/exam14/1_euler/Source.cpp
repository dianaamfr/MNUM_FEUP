#include <iostream>
#include <cmath>

using namespace std;

double c = 1, m = 20, k = 20;

double f1(double x, double y) {

  return -(k * x + c*y)/m;
}

double f2(double y) {
  return y;
}

void euler(double t0, double y0,double x0, int n, double h) {
  double t = t0, y = y0, x = x0, yant;
  for (unsigned int i = 0; i < n; i++) {
    yant = y;
    y += h*f1(x,y);
    x += h*f2(y);
  }
  cout << x;
}

int main() {
  euler(0.0,0.0,1.0,50,0.1);
  system("pause");
  return 0;
}