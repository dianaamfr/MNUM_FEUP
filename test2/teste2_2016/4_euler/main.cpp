#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

float Ta = 42;

float f(float T) {
  return -0.25 * (T - Ta);
}

float euler(float T0, float t0, float h, float n) {
  float T = T0, t = t0;
  for (unsigned int i = 0; i < n; i++) {
    T += h * f(T);
  }
  return T;
}

int main() {

  float s = euler(10.0, 5.0, 0.4, 2);
  cout << s;

  system("pause");
  return 0;
}