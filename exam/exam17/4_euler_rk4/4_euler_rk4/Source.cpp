#include <iostream>
#include <cmath>

using namespace std;

double b = 0.5;
double a = 30;
double c1 = 273;
double c2 = 20;

double dC(double T, double C) {
  return -exp(-b / (T + c1)) * C;
}

double dT(double T, double C) {
  return a * exp(-b / (T + c1)) * C - b * (T - c2);
}

//a
void euler(double t0, double C0, double T0, int n, double h) {

  double C=C0, t=t0, T=T0, Cant;
  cout << "Euler:\n";
  for (unsigned int i = 0; i <= n; i++) {
    cout << "(iteracao " << i << ")\n";
    cout << "t = " << t << "   " << "C = " << C << "   " << "T = " << T << endl;

    Cant = C;
    C += h*dC(T,C);
    T += h*dT(T,Cant);
    t += h;
  }
}

//b
void rk4(double t0, double C0, double T0, int n, double h) {
  double C = C0, t = t0, T = T0;
  double d1C, d2C, d3C, d4C, d1T, d2T, d3T, d4T;

  cout << "RK4:\n";
  for (unsigned int i = 0; i <= n; i++) {
    cout << "(iteracao " << i << ")\n";
    cout << "t = " << t << "   " << "C = " << C << "   " << "T = " << T << endl;

    d1C = h * dC(T, C);
    d1T = h * dT(T, C);
    d2C = h * dC(T + d1T/2,C +d1C/2);
    d2T = h * dT(T + d1T / 2, C + d1C / 2);
    d3C = h * dC(T + d2T / 2, C + d2C / 2);
    d3T = h * dT(T + d2T/2, C + d2C/2);
    d4C = h * dC(T + d3T, C + d3C);
    d4T = h * dT(T + d3T, C + d3C);
    T += d1T/6 + d2T/3 + d3T/3+d4T/6;
    C += d1C/ 6 + d2C / 3 + d3C / 3 + d4C / 6;
    t += h;
  }
}

//c
double euler_c(double t0, double C0, double T0, int n, double h) {

  double C = C0, t = t0, T = T0, Cant;
  for (unsigned int i = 0; i < n; i++) {
    Cant = C;
    C += h * dC(T, C);
    T += h * dT(T, Cant);
    t += h;
  }

  return T;
}


int main() {
  double t0 = 0, C0 = 2.5, T0 = 25;

  cout << "a)";
  euler(t0,C0,T0,2,0.25);
  cout << endl;
  cout << "b)";
  rk4(t0, C0, T0, 2, 0.25);
  cout << endl;
  cout << "c)";

  double S = euler_c(t0, C0, T0, 2.0, 0.25);
  double Sl = euler_c(t0, C0, T0, 2*2.0, 0.25/2.0);
  double Sll = euler_c(t0, C0, T0, 2 * 4.0, 0.25 / 4.0);

  cout << "S' = " << Sl << endl;
  cout << "S'' = " << Sll << endl;

  double qc = (Sl-S)/(Sll-Sl);
  double e = (Sll-Sl);

  cout << "Qc = " << qc << endl;
  cout << "E'' = " << e;

  system("pause");
  return 0;
}