#include <iostream>
#include <cmath>

using namespace std;

double r1(double x1, double x2, double x3, double x4) {
  return (x2+x3-x4+1) /4.8 ;
}

double r2(double x1, double x2, double x3, double x4) {
  return (x1 - x3 + x4 - 1) / 4.8;
}

double r3(double x1, double x2, double x3, double x4) {
  return (x1 -2*x2 + x4 - 1) / 4.8;
}

double r4(double x1, double x2, double x3, double x4) {
  return (-2*x1 + x2 + x3) / 4.8;
}

void gauss_seidel(double x1, double x2, double x3, double x4) {

  for (unsigned int i = 0; i < 2; i++) {
    cout << "X" << i + 1 << endl;

    x1 = r1(x1, x2, x3, x4);
    x2 = r2(x1, x2, x3, x4);
    x3 = r3(x1, x2, x3, x4);
    x4 = r4(x1, x2, x3, x4);
  
    cout << x1 << endl;
    cout << x2 << endl;
    cout << x3 << endl;
    cout << x4 << endl;
    cout << endl;
  }
}

int main() {

  gauss_seidel(0, 0, 0, 0);

  system("pause");
  return 0;
}