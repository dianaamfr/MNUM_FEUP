#include <cmath>
#include <iostream>
#include <vector>


using namespace std;

//outra versão
double b = 0.1;
double a = 15;
/*double b = 0.5;
double a = 20;*/


double dC(double t, double T, double C) {
  return -exp(-b / (T + 273)) * C;
}

double dT(double t, double T, double C) {
  return a * exp(-b / (T + 273)) * C - b * (T - 20);
}

void rk4(double t0, double T0, double C0, double h) {
  double dC1, dC2, dC3, dC4, dT1, dT2, dT3, dT4, t = t0, C = C0, T = T0;
  cout << "\n(b)RK4" << endl;
  for (unsigned int i = 0; i < 3; i++) {
    cout << i << endl;
    cout << "t: " << t << "    " << "C: " << C << "    " << "T: " << T << endl << endl;

    dC1 = h * dC(t, T, C);
    dT1 = h * dT(t, T, C);

    dC2 = h * dC(t + h / 2, T + dT1 / 2, C + dC1 / 2);
    dT2 = h * dT(t + h / 2, T + dT1 / 2, C + dC1 / 2);

    dC3 = h * dC(t + h / 2, T + dT2 / 2, C + dC2 / 2);
    dT3 = h * dT(t + h / 2, T + dT2 / 2, C + dC2 / 2);

    dC4 = h * dC(t + h, T + dT3, C + dC3);
    dT4 = h * dT(t + h, T + dT3, C + dC3);

    C += dC1 / 6 + dC2 / 3 + dC3 / 3 + dC4 / 6;
    T += dT1 / 6 + dT2 / 3 + dT3 / 3 + dT4 / 6;
    t += h;
  }


}

vector<double> euler(double t0, double T0, double C0, double h, int n) {
  double t = t0, C = C0, T = T0, Cant = C - 1;
  cout << "Euler (h = " << h << ")" << endl;
  unsigned int i = 0;

  for (i = 0; i < n; i++) {
    Cant = C;
    C += h * dC(t, T, C);
    T += h * dT(t, T, Cant);
    t += h;
  }
  cout << "n: " << i << endl;
  cout << "t: " << t << "    " << "C: " << C << "    " << "T: " << T << endl << endl;
  vector<double> v = { T,C };
  return v;
}

vector<double> eulerA(double t0, double T0, double C0,double h, int n) {
  double t = t0, C = C0, T = T0, Cant = C - 1;
  cout << "(a)(Euler (h = " << h << ")" << endl;
  unsigned int i = 0;
  cout << "n: " << i << endl;
  cout << "t: " << t << "    " << "C: " << C << "    " << "T: " << T << endl << endl;

  for (i = 0; i < n; i++) {
    Cant = C;
    C += h * dC(t, T, C);
    T += h * dT(t, T, Cant);
    t += h;

    cout << "n: " << i + 1 << endl;
    cout << "t: " << t << "    " << "C: " << C << "    " << "T: " << T << endl << endl;
  }

  vector<double> v = { T,C };
  return v;
}


int main() {
  //outra versão
  vector<double> v0 = eulerA(0.5, 20.0, 2.0, 0.25, 2);
  rk4(0.5, 20.0, 2.0, 0.25);

  cout << "(c)\n";
  vector<double> v1 = euler(0.5, 20.0, 2.0, 0.125, 2*2);
  vector<double> v2 = euler(0.5, 20.0, 2.0, 0.0625, 2*4);

  double QcC = (v1[1] - v0[1]) / (v2[1] - v1[1]);
  cout << " QcC = " << QcC << endl;
  cout << " EC = " << (v2[1] - v1[1]) << endl;

  /*vector<double> v0 = eulerA(0, 15.0, 1.0, 0.25, 2);
  rk4(0, 15, 1, 0.25);

  cout << "(c)\n";
  vector<double> v1 = euler(0, 15.0, 1.0, 0.25 / 2.0, 2 * 2);
  vector<double> v2 = euler(0, 15.0, 1.0, 0.25 / 4.0, 2 * 4);

  double QcC = (v1[1] - v0[1]) / (v2[1] - v1[1]);
  cout << " QcC = " << QcC << endl;
  cout << " EC = " << (v2[1] - v1[1]) << endl;*/

  system("pause");
  return 0;
}