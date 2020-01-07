#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

float recX(float x, float y, float z, float k){
  return (y+z-k+1)/4.5;
}

float recY(float x, float y, float z, float k) {
  return (x-z+k-1) /4.5 ;
}

float recZ(float x, float y, float z, float k) {
  return (x-2*y+k-1) /4.5 ;
}

float recK(float x, float y, float z, float k) {
  return (-2*x+y+z) /4.5 ;
}

void gauss_jacobi(float x, float y, float z, float k) {
  float xAnt, yAnt, zAnt;

  for (unsigned int i = 0; i < 2; i++) {
    xAnt = x;
    x = recX(x, y, z, k);
    yAnt = y;
    y = recY(xAnt, y, z, k);
    zAnt = z;
    z = recZ(xAnt, yAnt, z, k);
    k = recK(xAnt, yAnt, zAnt, k);

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << k << endl;
    cout << endl;
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << k << endl;
    cout << endl;
  }
}

int main() {
  gauss_jacobi(0.25, 0.25, 0.25, 0.25);
  system("pause");
  return 0;
}