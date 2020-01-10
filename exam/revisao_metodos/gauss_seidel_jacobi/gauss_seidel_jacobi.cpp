#include <cmath>
#include <iostream>

using namespace std;

double f1(double x1, double x2, double x3, double x4) {
  return (25.0-0.5*x2-3.0*x3-0.25*x4)/6.0;
}

double f2(double x1, double x2, double x3, double x4) {
  return (10.0 - 1.2 * x1 - 0.25 * x3 - 0.2 * x4) / 3.0;
}

double f3(double x1, double x2, double x3, double x4) {
  return (1.0 * x1 - 0.25 * x2 - 2.0 * x4 + 7.0) / 4.0;
}

double f4(double x1, double x2, double x3, double x4) {
  return (-12.0-2.0*x1-4.0*x2-1.0*x3) / 8.0;
}

void gauss_seidel(double x1, double x2, double x3, double x4, int n){
  cout << "Gauss Seidel:\n";
  
  for (unsigned int i = 0; i < n; i++) {
    x1 = f1(x1, x2, x3, x4);
    x2 = f2(x1, x2, x3, x4);
    x3 = f3(x1, x2, x3, x4);
    x4 = f4(x1, x2, x3, x4);

    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;
    cout << "x4 = " << x4 << endl;
    cout << endl;
  }
}

void gauss_jacobi(double x1, double x2, double x3, double x4, int n) {
  double x1ant, x2ant, x3ant;

  cout << "Gauss Jacobi:\n";
  for (unsigned int i = 0; i < n; i++) {
    x1ant = x1;
    x1 = f1(x1, x2, x3, x4);
    x2ant = x2;
    x2 = f2(x1ant, x2, x3, x4);
    x3ant = x3;
    x3 = f3(x1ant, x2ant, x3, x4);
    x4 = f4(x1ant, x2ant, x3ant, x4);

    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;
    cout << "x4 = " << x4 << endl;
    cout << endl;
  }
}

int main() {
  double x1 = 2.83865, x2 = 2.22131, x3 = 4.17630, x4 = -3.84236;
  gauss_jacobi(x1,x2,x3,x4,1);
  cout << endl;
  gauss_seidel(x1, x2, x3, x4,1);

  system("pause");
  return 0;
}