#include <iostream>
#include <cmath>

using namespace std;

double Ta = 37;

double dT(double T) { 
  return -0.25 * (T - Ta);
}

void euler(double h, double T0, double t, int n) {
  double T = T0;
  for (unsigned int i = 0; i < n; i++ ) {
    T += h * dT(T);
    t += h;
  }
  cout << "T = " << T << endl;
}

int main() {
  double T0 = 3, t0 = 5, h = 0.4;

  euler(h,T0,t0,2);
  system("pause");
  return 0;
}