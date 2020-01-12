#include <iostream>
#include <cmath>
using namespace std;

double r1(double x2, double x3) {
  return (-61.0*x2-41.0*x3+1.3)/103.0;
}

double r2(double x1, double x3) {
  return (-1.0 * x1 - 3.0 * x3) / 5.5;
}

double r3(double x1, double x2) {
  return (-2.0 * x1 - 10.0 * x2-13.0) / 13.0;
}

void gauss_seidel(double x1, double x2, double x3,int n) {
  for (unsigned int i = 0; i < n; i++) {
    x1 = r1(x2, x3);
    x2 = r2(x1, x3);
    x3 = r3(x1, x2);
  }
}

int main() {
  cout << "(a) I por ser diagonalmente dominante\n";
  cout << "(b) III pelo facto de o primeiro coeficiente ser unitario\n";
  cout << "(c)\n";
  cout << "xn+1 = (1.3 + -61.0 * yn + -41.0 * zn) / 103.0\n";
  cout << "yn+1 = (0.0 + -1.0 * xn+1 + -3.0 * zn) / 5.5\n";
  cout << "zn+1 = (-13.0 + -2.0 * xn+1 + -10.0 * yn+1) / 13.0\n";
  //gauss_seidel();

  system("pause");
  return 0;
}