#include <iostream>
#include <cmath>

using namespace std;

double Ta = 37;

double f(double T) {
  return -0.25 * (T-Ta);
}

void euler(double t0, double T0,double h, int n) {
  
  for (unsigned int i = 0; i < n; i++) {
    T0 += h*f(T0);
    t0 += h;
  }

  cout << T0 << endl;
}

int main() {
  double T0 = 3, t0 = 5, h = 0.4;
  euler(t0,T0,h,2);
  system("pause");
  return 0;
}