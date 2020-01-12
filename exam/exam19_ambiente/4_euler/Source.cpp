#include <cmath>
#include <iostream>
using namespace std;

double dz(double A, double B, double y, double z) {
  return A * z - B * y;
}

double dy(double z) {
  return z;
}

void euler(double A, double B, double x0, double y0, double z0, double h, int n) {
  double x = x0, y = y0, z = z0, yant;
  cout << "x = " << x0 << "       " << "y = " << "       " << y0 << "y' = " << z0 << endl;
  for (unsigned int i = 0; i < n; i++) {
    yant = y;
    y += h * dy(z);
    z += h * dz(A,B,yant,z);
    x += h;
    cout << "x = " << x << "       " << "y = " << y <<"       " << "y' = " << z << endl;
  }
}

int main() {
  double h = 0.8-0.6;
  double x0 = 0.6 - h, y0 = 2.0, z0 = 1.0;
  euler(-7.0,4.0,x0,y0,z0,h,3);

  system("pause");
  return 0;
}