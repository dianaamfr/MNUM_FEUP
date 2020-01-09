#include <iostream>
#include <cmath>

using namespace std;

double df(double x) {
  return 1.0 - 3.0 * pow(cos(x + 1.1), 2.0) * sin(x + 1.1);
}

double f(double x) {
  return x - 2.6 + pow(cos(x + 1.1), 3);
}

double newton(double x0, int n) {
  double x = x0;

  for (unsigned int i = 0; i < n; i++) {
    x -= f(x)/df(x);
  }

  return x;
}

int main() {

  cout << newton(1.8,1)<<endl << endl;

  system("pause");
  return 0;
}