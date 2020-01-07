#include <iostream>
#include <cmath>

using namespace std;

void trapezios_cub(float a, float A, float b, float B) {
  
  float sum, hx = (A-a) / 2.0, hy = (B-b)/2.0;
  float sum0 = 7.3 + 1.2 + 7.7 + 1.1;
  float sum1 = 1.5+1.4+2.2+2.1;
  float sum2 = 3.1;
  sum = (sum0 + sum1 * 2 + sum2 * 4) * hx * hy / 4;

  cout << sum;
}

int main() {

  trapezios_cub(0,2,0,2);

  system("pause");
  return 0;
}