#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

float r1(float x0, float x1, float x2, float x3) {
  return (-0.5*x1-3*x2-0.25*x3+2.5)/6;
}

float r2(float x0, float x1, float x2, float x3) {
  return (-1.2 * x0 - 0.25 * x2 - 0.2 * x3+3.8) / 3;
}

float r3(float x0, float x1, float x2, float x3) {
  return (1 * x0 - 0.25 * x1 - 2 * x3+10) / 4;
}

float r4(float x0, float x1, float x2, float x3) {
  return (-2 * x0 - 4 * x1 - 1 * x2+7) / 8;
}

void gauss_seidel(float x0, float x1, float x2, float x3) {
  x0 = r1(x0, x1, x2, x3);
  x1 = r2(x0, x1, x2, x3);
  x2 = r3(x0, x1, x2, x3);
  x3 = r4(x0, x1, x2, x3);

  cout << x0 << endl;
  cout << x1 << endl;
  cout << x2 << endl;
  cout << x3 << endl;
}

int main() {

  gauss_seidel(0, 0, 0, 0);

  system("pause");
  return 0;
}