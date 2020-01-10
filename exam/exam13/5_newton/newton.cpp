#include <cmath>
#include <iostream>
using namespace std;

double df(double x) {
  return 1.0 - 3.0 * pow(cos(x + 1.2),2) * sin(x + 1.2);
}

double f(double x) {
  return (x - 3.7) + pow(cos(x + 1.2),3);
}

void newton(double guess, int n) {
  double x = guess;
  for (unsigned int i = 0; i < n; i++) {
    x = x - f(x) / df(x);
    cout << x;
  }
}

int main() {
  newton(3.8,1);
  system("pause");
  return 0;
}