#include <iostream>
#include <cmath>

using namespace std;

double A = 0.5;

double dy(double z) {
  return z;
}

double dz(double t, double z) {
  return A + t * t + t * z;
}

void euler(double t0, double y0, double z0, double h) {
  double t = t0, y = y0, z = z0;
  cout << "Euler\n";
  for (unsigned int i = 0; i <= 2; i++) {

    cout << i << "        " << t << "        " << y << endl;

    y += h*dy(z);
    z += h*dz(t,z);
    t += h;
  }
}

void rk4(double t0, double y0, double z0, double h) {
  double t = t0, y = y0, z = z0, d1y, d2y, d3y, d4y, d1z, d2z, d3z, d4z;
  cout << "RK4\n";
  for (unsigned int i = 0; i <= 2; i++) {

    cout << i << "        " << t << "        " << y << endl;

    d1y = h*dy(z);
    d1z = h * dz(t, z);

    d2y = h * dy(z+d1z/2);
    d2z = h * dz(t+h/2,z + d1z / 2);

    d3y = h * dy(z + d2z / 2);
    d3z = h * dz(t + h / 2, z + d2z / 2);

    d4y = h * dy(z + d3z);
    d4z = h * dz(t + h, z + d3z);

    y += d1y / 6 + d2y / 3 + d3y / 3 + d4y / 6;
    z += d1z / 6 + d2z / 3 + d3z / 3 + d4z / 6;
    t += h;
  }
}

int main() {

  euler(0, 0, 1,0.25);
  cout << endl;
  rk4(0, 0, 1, 0.25);
  system("pause");
  return 0;
}