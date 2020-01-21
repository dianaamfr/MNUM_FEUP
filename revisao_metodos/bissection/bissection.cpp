#include <cmath>
#include <iostream>
using namespace std;

double f(double x){
  return pow(x,3) -10*sin(x)+2.8;
}

void bissection(double a, double b, int n) {
  double c;
  cout << "";
  for (unsigned int i = 0; i <= n; i++) {
    
    c = (a + b) / 2.0;

    cout << "a = " << a << "     " << "b = " << b << "      ";
    cout << "c = " << c << endl;
    cout << "f(a) = " << f(a) << "     " << "f(b) = " << f(b) << "      ";
    cout << "f(c) = " << f(c) << endl << endl;;

    if (f(a)*f(c)<0) {
      b = c;
    }
    else {
      a = c;
    }
  }
}

int main() {
  bissection(1.5,4.2,2);
  system("pause");
  return 0;
}