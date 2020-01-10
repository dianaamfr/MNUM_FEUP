#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
  return 5.0 * cos(x) - sin(x);
}

void tercos(double x1, double x2, int n){
  double x3, x4, dist;

  for (unsigned int i = 0; i < n; i++) {
    dist = (x2 - x1) / 3.0;
    x3 = x1 + dist;
    x4 = x1 + 2.0 * dist;

    if (f(x4) < f(x3)) {
      x1 = x3;
    }
    else {
      x2 = x4;
    }
  }

  if (x1 == x3) {
    cout << "x1 = " << x1<<  "    "<< "f(x1) = " << f(x1) << endl ;
    cout << "x4 = " << x1 << "    " << "f(x4) = " << f(x4) << endl;
    cout << "x2 = " << x2 << "    " << "f(x2) = " << f(x2) << endl;
    cout << endl;
  }
  else {
    cout << "x1 = " << x1 << "    " << "f(x1) = " << f(x1) << endl;
    cout << "x3 = " << x3 << "    " << "f(x3) = " << f(x3) << endl;
    cout << "x2 = " << x2 << "    " << "f(x2) = " << f(x2) << endl;
    cout << endl;
  }
}

int main() {

  double x1 = 2, x2 = 4;
  tercos(x1,x2,4);
  system("pause");
  return 0;
}