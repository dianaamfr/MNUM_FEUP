#include <cmath>
#include <iostream>
using namespace std;

double g(double x){
  return 2.0 * log(2.0 * x);
}

void picard_peano(double x0,int n) {
  double x = x0;

  cout << "x = " << x << endl;
  for (unsigned int i = 0; i < n; i++) {
    x = g(x);
    cout << "x = " << x << endl;
  }
  cout << "residuo = " << abs(x - x0);
}

int main() {
  picard_peano(0.9,1);
  system("pause");
  return 0;
}