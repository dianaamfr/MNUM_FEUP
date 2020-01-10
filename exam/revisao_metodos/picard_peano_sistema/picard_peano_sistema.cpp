#include <cmath>
#include <iostream>
using namespace std;

double r1(double x, double y) {
  return sqrt((x * y + 5 * x - 1) / 2);;
}

double r2(double x, double y) {
  return sqrt(x + 3 * log(x));
}

void picard_peano(double x0, double y0, int n) {
  double x = x0, y = y0, xant;

  cout << "n = " << 0 << "         " << "x = " << x << "    " << "y = " << y << endl;
  
  for (unsigned int i = 0; i < n; i++) {
    xant = x;
    x = r1(x, y);
    y = r2(x, y);

    cout << "n = " << i+1 << "         " << "x = " << x << "    " << "y = " << y << endl;
  }
}

int main() {
  picard_peano(4.0,4.0,22);
  system("pause");
  return 0;
}