#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
  return 5 * cos(x) - sin(x);
}

void aurea(double x1, double x2, int n) {

  double x3, x4;
  double B = (sqrt(5) - 1) / 2;
  double A = pow(B, 2);
  double intervalo = 0;

  cout << "Seccao Aurea: \n";
  for (unsigned int i = 0; i <= n; i++) {

    x3 = x1 + A*(x2-x1);
    x4 = x1 + B*(x2-x1);

    intervalo = abs(x4 - x1);

    cout << "f( " << x1 << " ) = " << f(x1) << endl;
    cout << "f( " << x2 << " ) = " << f(x2) << endl;
    cout << "f( " << x3 << " ) = " << f(x3) << endl;
    cout << "f( " << x4 << " ) = " << f(x4) << endl;
    cout << endl;

    if (f(x3) < f(x4))
      x2 = x4;
    else
      x1 = x3;
    
  }

  cout << "Intervalo: " << intervalo<<endl;
}

int main() {
  double x1 = 2, x2 = 4;

  aurea(x1,x2,2);

  system("pause");
  return 0;
}

