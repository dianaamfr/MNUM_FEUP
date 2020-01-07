#include <iostream>
#include <cmath>

using namespace std;

double r1(double x2, double x3, double x4) {
  return (-0.5*x2-3*x3-0.25*x4+25)/ 6.0;
}

double r2(double x1, double x3, double x4) {
  return (-1.2 * x1 - 0.25 * x3 - 0.2 * x4+10) / 3.0;
}

double r3(double x1, double x2, double x4) {
  return (x1 - 0.25 * x2 - 2 * x4+7) /4.0;
}

double r4(double x1, double x2, double x3) {
  return (-2 * x1 -4 * x2 - 1 * x3-12) /8.0;
}

void gauss_seidel(double x1, double x2, double x3, double x4) {
  for (unsigned int i = 0; i < 1; i++) {
    x1 = r1(x2, x3, x4);
    x2 = r2(x1, x3, x4);
    x3 = r3(x1, x2, x4);
    x4 = r4(x1, x2, x3);
  }

  cout << x1 << endl << x2 << endl << x3 << endl << x4 << endl;
}

int main() {

  gauss_seidel(2.12687, 2.39858, 3.99517, -3.73040);

  system("pause");
  return 0;
}