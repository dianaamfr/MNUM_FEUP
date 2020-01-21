#include <cmath>
#include <iostream>

using namespace std;

double A = 0.5;

double dy(double z) {
  return z;
}

double dz(double t, double z) {
  return A + pow(t, 2) + t * z;
}

void euler(double t0, double y0, double z0, double h, int n) {
  double y = y0, t = t0, z = z0;

  cout << 0 << "        " << "t = " << t << "       " << "y = " << y << endl;

  for (unsigned int i = 0; i < n; i++) {
    y += h * dy(z);
    z += h * dz(t,z);
    t += h;

    cout << i+1 << "        " << "t = " << t << "       " << "y = " << y << endl;
  }
}

void rk4(double t0, double y0, double z0, double h, int n) {
  double d1y, d2y, d3y, d4y, d1z, d2z, d3z, d4z;
  double y=y0, t=t0, z=z0;

  cout << 0 << "        " << "t = " << t << "       " << "y = " << y << endl;

  for (unsigned int i = 0; i < n; i++) {

    d1y = h * dy(z);
    d1z = h * dz(t, z);
    d2y = h * dy(z+d1z/2.0);
    d2z = h * dz(t+h/2.0, z + d1z / 2.0);
    d3y = h * dy(z + d2z / 2.0);
    d3z = h * dz(t + h / 2.0, z + d2z / 2.0);
    d4y = h * dy(z + d3z);
    d4z = h * dz(t + h, z + d3z);

    y += d1y / 6.0 + d2y / 3.0 + d3y / 3.0 + d4y / 6.0;
    z += d1z / 6.0 + d2z / 3.0 + d3z / 3.0 + d4z / 6.0;
    t += h;

    cout << i + 1 << "        " << "t = " << t << "       " << "y = " << y << endl;
  }

}

int main() {
  double h = 0.25, t0 = 0, y0 = 0, z0 = 1;
  euler(t0,y0,z0,h,2);
  cout << endl;
  rk4(t0, y0, z0, h, 2);
  system("pause");
  return 0;
}