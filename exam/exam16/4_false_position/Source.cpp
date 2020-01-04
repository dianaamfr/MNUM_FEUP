#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double a = 1;
double b = 0.5;
double c = 0.5;

double f(double x) {
  return a * pow(x, 7) + b * x - c;
}

void false_position(double xe, double xd, int n) {
  
  double xn = 0;
  cout << "xe" << "         " << "xd" << "         " << "xn" << endl;
  for (unsigned int i = 0; i <= n; i++) {
    xn = (xe*f(xd)-xd*f(xe))/(f(xd)-f(xe));
    cout << xe << "         " <<xd << "         " << xn << endl;

    if (f(xn) * f(xe) < 0) xd = xn;
    else xe = xn;
  }
}

int main() {
  double xe = 0;
  double xd = 0.8;
  
  false_position(xe, xd, 3);

  system("pause");
  return 0;
}