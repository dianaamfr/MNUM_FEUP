#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double f(double x, double y) {
  return pow(y, 2) - 2 * x * y - 6 * y + 2 * pow(x, 2) + 12;
}

double dfx(double x, double y) {
  return -2 * y + 4 * x;
}

double dfy(double x, double y) {
  return 2 * y - 2 * x - 6;
}

void gradiente_Iter(double x, double y, double h, int n) {
  double xn, yn;
  for (unsigned int i = 0; i < n;  i++) {
    xn = x - h * dfx(x, y);
    yn = y - h * dfy(x, y);

    if (f(xn, yn) > f(x, y))
      h /= 2;
    else
    {
      x = xn;
      y = yn;
      h *= 2;
    }
  }
  

  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
  cout << "f(x,y) = " << f(x, y) << endl;
}

void gradiente(double x, double y, double h, double precision) {
  double xant=x-1,yant=y-1,xtemp,ytemp;

  do {
    xtemp = x - h * dfx(x, y);
    ytemp = y - h * dfy(x, y);
    
    if (f(xtemp, ytemp) < f(xant, yant)) {
      xant = x;
      yant = y;
      x = xtemp;
      y = ytemp;
      h *= 2;
    }
    else {
      h /= 2;
    }
  } while(abs(x - xant) > precision || abs(y- yant) > precision);

  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
  cout << "f(x,y) = " << f(x,y) << endl;

}

int main() {
  double x = 1, y = 1, h = 1, precision = 0.01;
  int n = 20;
  //precisao relativa
  gradiente(x, y, h, precision);
  cout << endl;
  //anulacao da raiz
  gradiente_Iter(x,y,h,n);

  system("pause");
  return 0;
}