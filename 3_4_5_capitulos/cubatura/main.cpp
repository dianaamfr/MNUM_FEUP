#include <iostream>

using namespace std;

double f(double x, double y)
{
  return exp(y - x);
}

void trapeziosCubatura(double A, double a, double B, double b, double nx, double ny)
{
  double hx, hy, s = 0;

  hx = (A - a) / (double)nx;
  hy = (B - b) / (double)ny;

  s += f(a, b) + f(a, B) + f(A, b) + f(A, B);
  s += 2 * (f(a, b + hy) + f(a + hx, b) + f(A, b + hy) + f(a + hx, B));
  s += 4 * f(a + hx, b + hy);
  s = ((hx * hy) / 4.0) * s;
  cout << "\nResultado pelo Metodo dos Trapezios: " << s << endl;
}

void simpsonCubatura(double A, double a, double B, double b, double nx, double ny)
{
  double hx, hy, s = 0;

  hx = (A - a) / (double)nx;
  hy = (B - b) / (double)ny;

  s += f(a, b) + f(a, B) + f(A, b) + f(A, B);
  s += 4 * (f(a, b+hy) + f(a+hx, b) + f(A, b+hy) + f(a+hx, B));
  s += 16 * f(a+hx, b+hy);
  s = ((hx * hy) / 9.0) * s;
  cout << "\nResultado pelo Metodo de Simpson: " << s << endl;
}

int main()
{
  trapeziosCubatura(0.5, 0, 0.5, 0, 2, 2);
  simpsonCubatura(0.5, 0, 0.5, 0, 2, 2);

  system("pause");
  return 0;
}