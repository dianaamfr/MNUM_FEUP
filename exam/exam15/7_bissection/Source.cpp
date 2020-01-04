#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
  return pow(x, 3) - 10 * sin(x) + 2.8;
}

void bissection(double a, double b, int n) {
  double xn;

  for (int i = 0; i <= n; i++) {
    xn = (a + b) / 2;
    if (f(a) * f(xn) < 0) b = xn;
    else a = xn;
  }
  cout << b; /*extremo superior do intervalo que contém a raíz na 2ª iteração - sendo a iteração 0 a que usa os valores iniciais para o cálculo*/
}

int main() {
  bissection(1.5, 4.2, 2);
  system("pause");
  return 0;
}