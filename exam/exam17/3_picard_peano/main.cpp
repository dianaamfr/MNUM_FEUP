#include <iostream>
#include <cmath>
using namespace std;

double r(double x) {
  return log(5 + x);
}

double f(double x) {
  return exp(x) - x - 5;
}

double df(double x) {
  return exp(x) - 1;
}

void newton(double guess, double precision) {
  double x=guess, xant = x - 1;
  int n = 0;

  while (abs(x-xant) > precision) {
    xant = x;
    x = xant - f(xant) / df(xant);
    n++;
  }

  cout << "Newton ( " << n << " iteracoes) x = " << x << endl;
}

void picard_peano(double guess, double precision) {
  double x = guess, xant = x - 1;
  int n = 0;
  while (abs(x-xant)>precision) {
    xant = x;
    x = r(xant);
    n++;
  }

  cout << "Picard Peano ( " << n << " iteracoes) x = " << x << endl;
}

int main() {

  double precision = pow(10, -5);
  double guess = 2;

  picard_peano(guess,precision);
  newton(guess, precision);
  system("pause");
  return 0;
}