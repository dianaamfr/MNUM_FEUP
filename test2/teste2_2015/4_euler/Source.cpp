#include <iostream>
#include <cmath>

using namespace std;

float Ta = 45;

float f(float T) {
  return -0.25*(T - Ta);
}

void euler(float t0, float T0, float h){
  float T = T0;
  for (int i = 0; i < 2; i++) {
    T += h * f(T);
  }
  cout << "T = " << T;
}

int main() {

  euler(1,23,0.4);

  system("pause");
  return 0;
}