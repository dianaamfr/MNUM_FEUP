#include <iostream>
#include <cmath>

using namespace std;

double a = 3;
double B = (sqrt(5) - 1) / 2;
double A = pow(B, 2);

double f(double x) {
  return pow(x - a, 2) + pow(x, 4);
}

void tercos(double x1, double x2, double precision){
  double dist;
  double x3=0, x4=0;

  while (abs(x2-x1) > precision) {
    dist = abs(x2 - x1) / 3;
    x3 = x1 + dist;
    x4 = x1 + 2 * dist;

    if (f(x3) > f(x4))
      x1 = x3;
    else
      x2 = x4;
  }

  cout << "Tercos:\n";

  if (x1 == x3) {
    cout << "a = " << x3 << "     " << " f(a) = " << f(x3) << endl;
    cout << "b = " << x4 << "     " << " f(b) = " << f(x4) << endl;
    cout << "c = " << x2 << "     " << " f(c) = " << f(x2) << endl;
  }
  else {
    cout << "a = " << x1 << "     " << " f(a) = " << f(x1) << endl;
    cout << "b = " << x3 << "     " << " f(b) = " << f(x3) << endl;
    cout << "c = " << x4 << "     " << " f(c) = " << f(x4) << endl;
  }
  cout << endl;
}

void aurea(double x1, double x2, double precision) {
  double x3=0, x4=0;

  while(abs(x2-x1) > precision){

    x3 = x1 + A * (x2 - x1);
    x4 = x1 + B * (x2 - x1);
    
    if (f(x3) < f(x4)) {
      x2 = x4;
    }
    else {
      x1 = x3;
    }
  }


  cout << "Aurea:\n";
  cout << "x1 = " << x1 << "  " << "f(x1) = " << f(x1) << endl;
  cout << "x2 = " << x2 << "  " << "f(x2) = " << f(x2) << endl;
  cout << "x3 = " << x3 << "  " << "f(x3) = " << f(x3) << endl;
  cout << "x4 = " << x4 << "  " << "f(x4) = " << f(x4) << endl;
 
  cout << endl;
}

int main() {
  double precision = pow(10,-3);
  double x1 =0, x2 =2;
  //Tercos
  tercos(x1,x2,precision);
  //Aurea
  aurea(x1, x2, precision);
}