#include <iostream>
#include <cmath>

using namespace std;

double simpson_cubatura() {

  double hx = (1.8 - 0) / 2.0;
  double hy = (1.8 - 0) / 2.0;

  double sum0 = 1.1 + 6.3 + 1.2 + 2.6;
  double sum1 = 2.1 + 1.5 + 2.2 + 1.4;
  double sum2 = 4.9;

  return hx * hy * (sum0 + 4 * sum1 + 16 * sum2) / 9.0;

}

int main() {

  cout << simpson_cubatura();

  system("pause");
  return 0;
}