#include <iostream>
#include <cmath>
using namespace std;

double r(double x) {
  return 2.0*log(2.0*x);
}

void picard_peano(double x0) {
  double xn = r(x0);
  cout << xn << endl;
  cout << "residuo: " << abs(xn - x0);
}

int main() {
  double x0 = 1.1;
  picard_peano(x0);

  system("pause");
  return 0;
}