#include <iostream>
#include <cmath>

using namespace std;

double r(double x){
  return pow((4.0 *pow(x,3.0) - x + 1.0),1 / 4.0);
}

void picard_peano(double guess, double n) {
  for (unsigned int i = 0; i <= n; i++) {
    cout << "x = " << guess << endl;
    guess = r(guess);
  }
}

int main() {
  double guess = 4;
  picard_peano(4,2);
  system("pause");
  return 0;
}