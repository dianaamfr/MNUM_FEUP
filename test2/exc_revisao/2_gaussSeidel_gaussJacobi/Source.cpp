#include <iostream>
#include <cmath>

using namespace std;

double r1(double x1, double x2, double x3) {
  return (6*x2+x3-38)/2;
}

double r2(double x1, double x2, double x3) {
  return (3*x1-7*x3-34)/(-1);
}

double r3(double x1, double x2, double x3) {
  return (8*x1-x2-20)/(-2);
}

void gaussSeidel(double x1, double x2, double x3) {
  double x1ant, x2ant, x3ant;

  do{
    x1ant = x1;
    x2ant = x2;
    x3ant = x3;


    x1 = r1(x1,x2,x3);
    x2 = r2(x1, x2, x3);
    x3 = r3(x1, x2, x3);

  } while (abs(x1 - x1ant) > 0.01 || abs(x2 - x2ant) > 0.01 || abs(x3 - x3ant) > 0.01);


  cout << "x1: " << x1 << endl;
  cout << "x2: " << x2 << endl;
  cout << "x3: " << x3 << endl;
  cout << endl;
}

void gaussJacobi(double x1, double x2, double x3) {
  double x1ant, x2ant,x3ant;

  do{
    x1ant = x1;
    x2ant = x2;
    x3ant = x3;
    x1 = r1(x1, x2, x3);
    x2 = r2(x1ant, x2, x3);
    x3 = r3(x1ant, x2ant, x3);

  } while (abs(x1 - x1ant) > 0.01 || abs(x2 - x2ant) > 0.01 || abs(x3 - x3ant) > 0.01);

  cout << "x1: " << x1 << endl;
  cout << "x2: " << x2 << endl;
  cout << "x3: " << x3 << endl;
  cout << endl;
}

int main() {

  cout << "Gauss Jacobi\n";
  gaussJacobi(0,0,0);

  cout << "Gauss Seidel\n";
  gaussSeidel(0, 0,0);

  system("pause");
  return 0;
}