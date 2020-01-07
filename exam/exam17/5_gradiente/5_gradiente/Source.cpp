#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) {
  return -1.1 * x * y + 12 * y + 7 * pow(x, 2) - 8 * x;
}

double dfx(double x, double y) {
  return -1.1 * y + 14 * x - 8;
}

double dfy(double x, double y) {
  return 12 - 1.1 * x;
}

void gradiente(double x0, double y0, double lambda) {
  
  double x = x0 - lambda * dfx(x0, y0);
  double y = y0 - lambda * dfy(x0, y0);;
  cout << f(x, y);
}

int main() {
  double x0 = 3, y0 = 1, lambda = 0.1;

  gradiente(x0,y0,lambda);
  system("pause");
  return 0;
}