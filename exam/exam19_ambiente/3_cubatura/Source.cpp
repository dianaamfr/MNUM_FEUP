#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) {
  if (x == (double)0.0 && y == (double)0.0) return 1.1;
  else if (x == (double)1.0 && y == (double)1.0) return 4.0;
  else if (x == (double)2.0 && y == (double)2.0) return 1.2;
  else if (x == (double)0.0 && y == (double)1.0) return 2.1;
  else if (x == (double)0.0 && y == (double)2.0) return 7.8;
  else if (x == (double)1.0 && y == (double)0.0) return 1.4;
  else if (x == (double)2.0 && y == (double)1.0) return 2.2;
  else if (x == (double)1.0 && y == (double)2.0) return 1.5;
  else if (x == (double)2.0 && y == (double)0.0) return 9.8;
  else cout << "Error " << x << "   " << y << "\n";
}

void simpson(double a, double b, double A, double B) {
  double hx = (A - a) / 2.0;
  double hy = (B - b) / 2.0;

  double s = f(a,b) + f(a,B) + f(A,b) + f(A,B);
  s += 4*(f(a + hx,b)+f(a+hx,B)+f(a,b+hy)+f(A,b+hy));
  s += 16*f(a+hx,b+hy);

  s *= hx * hy / 9.0;
  cout << s << endl;
}

int main() {
  simpson(0.0,0.0,2.0,2.0);

  system("pause");
  return 0;
}