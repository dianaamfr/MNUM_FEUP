#include <iostream>
#include <cmath>

using namespace std;

float g(double t, double y, double z) {
  return 2 + pow(t, 2) + t * z;
}

float f(double t, double y, double z) {
  return z;
}

void euler(float h, float t0, float y0,float z0) {
  float t = t0, y = y0, z = z0, ytemp;

  cout << "Euler: \n";
  
  for (int i = 0; i < 3; i++) {
    cout << i << ": \n";
    cout << "t " << t << "    " << "y " << y << endl;
    ytemp = y;
    y = y + h * f(t,y,z);
    z = z + h * g(t, y, z);
    t = t + h;
  }
}

void rk4(float h, float t0, float y0,float z0) {
  float t = t0, y = y0, z = z0, d1y, d2y, d3y, d4y, d1z, d2z, d3z, d4z;
  cout << "\nRK4: \n";

  for (int i = 0; i < 3; i++) {
    cout << i << ": \n";
    cout << "t " << t << "    " << "y " << y << endl;

    d1y = h * f(t, y, z);
    d1z = h * g(t, y, z);

    d2y = h * f(t + h / 2, y + d1y/2.0, z + d1z/2.0);
    d2z = h * g(t + h / 2, y + d1y/2.0, z + d1z/2.0);

    d3y = h * f(t + h / 2, y + d2y/2.0, z + d2z/2.0);
    d3z = h * g(t + h / 2, y + d2y/2.0, z + d2z/2.0);

    d4y = h * f(t + h, y + d3y, z + d3z);
    d4z = h * g(t + h, y + d3y, z + d3z);

    y += d1y / 6 + d2y / 3 + d3y / 3 + d4y / 6;
    z += d1z / 6 + d2z / 3 + d3z / 3 + d4z / 6;
    t += h;

  }
}

int main() {
  int nIter = 2;
  euler(0.25,1,1,0);
  rk4(0.25,1,1,0);

  system("pause");
  return 0;
}