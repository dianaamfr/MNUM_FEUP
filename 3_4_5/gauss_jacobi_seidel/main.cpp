#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//exercicio aula
//formulas de recorrencia

double r1(double x1,double x2, double x3) {
  return (7-x2-x3) / 3;
}

double r2(double x1, double x2, double x3) {
  return (4 - x1 - 2 * x3) / 4;
}

double r3(double x1, double x2, double x3) {
  return (5 - 2 * x2) / 5;
}

//residuos

double res1(double x1, double x2, double x3) {
  return abs(3 * x1 + x2 + x3 - 7);
}

double res2(double x1, double x2, double x3) {
  return abs(x1 + 4 * x2 + 2 * x3 - 4);
}

double res3(double x1, double x2, double x3) {
  return abs(2 * x2 + 5 * x3 - 5);
}


//exercicio livro
//formulas de recorrencia
/*double r1(double x1,double x2, double x3) {
  return (24-2*x2) / 7;
}

double r2(double x1, double x2, double x3) {
  return (27 - 4*x1 - x3) / 10;
}

double r3(double x1, double x2, double x3) {
  return (27 - 5 *x1+ 2*x2) / 8;
}*/

//residuos
/*
double res1(double x1, double x2, double x3) {
  return abs(7 * x1 + 2*x2 - 24);
}

double res2(double x1, double x2, double x3) {
  return abs(4*x1 + 10 * x2 +x3 - 27);
}

double res3(double x1, double x2, double x3) {
  return abs(5*x1-2 * x2 + 8 * x3 - 27);
}*/


void gaussJacobi(double x1, double x2, double x3,double stop, int n = 0) {
  double x1ant, x2ant, x3ant;
  cout << setw(3) << "n" << setw(15) << "x1" << setw(15) << "x2" << setw(15) << "x3" << setw(15) << "res1" << setw(15) << "res2" << setw(15) << "res3" << endl;

  x1ant = x1;
  x2ant = x2;
  x3ant = x3;
  if(n==0){
    do {

      cout << setw(3) << n << setw(15) << x1 << setw(15) << x2 << setw(15) << x3;
      cout << setw(15) << res1(x1, x2, x3) << setw(15) << res2(x1, x2, x3) << setw(15) << res3(x1, x2, x3) << endl;

      x1ant = x1;
      x2ant = x2;
      x3ant = x3;

      x1 = r1(x1ant, x2ant, x3ant);
      x2 = r2(x1ant, x2ant, x3ant);
      x3 = r3(x1ant, x2ant, x3ant);

      n++;
    } while (abs(x1 - x1ant) > stop || abs(x2 - x2ant) > stop || abs(x3 - x3ant) > stop);

    cout << setw(3) << n << setw(15) << x1 << setw(15) << x2 << setw(15) << x3;
    cout << setw(15) << res1(x1, x2, x3) << setw(15) << res2(x1, x2, x3) << setw(15) << res3(x1, x2, x3) << endl;
  }
   else {
   for (unsigned int i = 1; i < n + 1; i++) {

     cout << setw(3) << i << setw(15) << x1 << setw(15) << x2 << setw(15) << x3;
     cout << setw(15) << res1(x1, x2, x3) << setw(15) << res2(x1, x2, x3) << setw(15) << res3(x1, x2, x3) << endl;

     x1ant = x1;
     x2ant = x2;
     x3ant = x3;

     x1 = r1(x1ant, x2ant, x3ant);
     x2 = r2(x1ant, x2ant, x3ant);
     x3 = r3(x1ant, x2ant, x3ant);

   }
   cout << setw(3) << n << setw(15) << x1 << setw(15) << x2 << setw(15) << x3;
   cout << setw(15) << res1(x1, x2, x3) << setw(15) << res2(x1, x2, x3) << setw(15) << res3(x1, x2, x3) << endl;
  }
}

void gaussSeidel(double x1, double x2, double x3, double stop,int n = 0) {
  double x1ant, x2ant, x3ant;
  cout << setw(3) << "n" << setw(15) << "x1" << setw(15) << "x2" << setw(15) << "x3" << setw(15) << "res1" << setw(15) << "res2" << setw(15) << "res3" << endl;
  if (n == 0) {
    do {

      cout << setw(3) << n << setw(15) << x1 << setw(15) << x2 << setw(15) << x3;
      cout << setw(15) << res1(x1, x2, x3) << setw(15) << res2(x1, x2, x3) << setw(15) << res3(x1, x2, x3) << endl;

      x1ant = x1;
      x2ant = x2;
      x3ant = x3;

      x1 = r1(x1ant, x2ant, x3ant);
      x2 = r2(x1, x2ant, x3ant);
      x3 = r3(x1, x2, x3ant);

      n++;
    } while (abs(x1 - x1ant) > stop || abs(x2 - x2ant) > stop || abs(x3 - x3ant) > stop);

    cout << setw(3) << n << setw(15) << x1 << setw(15) << x2 << setw(15) << x3;
    cout << setw(15) << res1(x1, x2, x3) << setw(15) << res2(x1, x2, x3) << setw(15) << res3(x1, x2, x3) << endl;

  }
  else {
    for (unsigned int i = 1; i < n+1; i++) {
      cout << setw(3) << i << setw(15) << x1 << setw(15) << x2 << setw(15) << x3;
      cout << setw(15) << res1(x1, x2, x3) << setw(15) << res2(x1, x2, x3) << setw(15) << res3(x1, x2, x3) << endl;

      x1ant = x1;
      x2ant = x2;
      x3ant = x3;

      x1 = r1(x1ant, x2ant, x3ant);
      x2 = r2(x1, x2ant, x3ant);
      x3 = r3(x1, x2, x3ant);
    }
    cout << setw(3) << n << setw(15) << x1 << setw(15) << x2 << setw(15) << x3;
    cout << setw(15) << res1(x1, x2, x3) << setw(15) << res2(x1, x2, x3) << setw(15) << res3(x1, x2, x3) << endl;
  }
}

int main() {
  double x1 = 0, x2 = 0, x3 = 0;
  double stop = pow(10, -3);

  //aula
  cout << "Gauss Jacobi: " << endl;
  gaussJacobi(x1,x2,x3,stop);

  cout << "Gauss Seidel: " << endl;
  gaussSeidel(x1, x2, x3, stop);

  //livro
  /*cout << "Gauss Jacobi: " << endl;
  gaussJacobi(x1, x2, x3, stop,4);

  cout << "Gauss Seidel: " << endl;
  gaussSeidel(x1, x2, x3, stop,4);*/
  system("pause");
  return 0;
}