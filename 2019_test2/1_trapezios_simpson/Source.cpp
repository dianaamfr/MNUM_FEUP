#include <iostream>
#include <cmath>
using namespace std;

double f(float t) {
  if (t == (float)0) return 0;
  else if (t == (float)1) return 0.0009706725;
  else if (t == (float)2) return 0.0785307606;
  else if (t == (float)3) return 0.4296244757;
  else if (t == (float)4) return 1.3824921700;

  else if (t == (float)5) return 3.3966703370;
  else if (t == (float)6) return 7.0629916108;
  else if (t == (float)7) return 13.1035847665;
  else if (t == (float)8) return 22.3718747204;

  else if (t == (float)9) return 35.8525825294;
  else if (t == (float)10) return 54.6617253916;
  else if (t == (float)11) return 80.0466166458;
  else if (t == (float)12) return 113.3858657720;

  else if (t == (float)13) return 156.1893783909;
  else if (t == (float)14) return 210.0983562643;
  else if (t == (float)15) return 276.8852972949;
  else if (t == (float)16) return 358.4539955264;

  else cout << "ERROR" << endl;
}

float trapezios(float t0, float tf, float h) {
  int n = (tf - t0) / h;
  double s = f(t0) + f(tf);

  for (unsigned int i = 1; i < n; i++) {
    s += 2 * f(t0 + i * h);
  }

  return s * (h / 2.0);
}

float simpson(float t0, float tf, float h) {
  int n = (tf - t0) / h;
  double s = f(t0) + f(tf);

  for (unsigned int i = 1; i < n; i++) {
    if (i % 2 == 0)
      s += 2 * f(t0 + i * h);
    else
      s += 4 * f(t0 + i * h);
  }

  return s * (h / 3.0);
}

int main() {

  float s = trapezios(0, 16, 4);
  float sl = trapezios(0, 16, 2);
  float sll = trapezios(0, 16, 1);
  float qc = (sl - s) / (sll - sl);
  float e = (sll - sl) / 3.0;

  cout << "(a)\n";
  cout << "Trapezios\n";
  cout << "(h = 1) St = " << s << endl;
  cout << "(h' = 2) St' = " << sl << endl;
  cout << "(h'' = 4) St'' = " << sll << endl;
  cout << "Qc = " << qc << endl;
  cout << "E = " << e << endl;

  s = simpson(0.0, 16.0, 4.0);
  sl = simpson(0.0, 16.0, 2.0);
  sll = simpson(0.0, 16.0, 1.0);
  qc = (sl - s) / (sll - sl);
  e = (sll - sl) / 15.0;

  cout << "Simpson\n";
  cout << "(h = 1) Ss = " << s << endl;
  cout << "(h' = 2) Ss' = " << sl << endl;
  cout << "(h'' = 4) Ss'' = " << sll << endl;
  cout << "Qc = " << qc << endl;
  cout << "E = " << e << endl;



  system("pause");
  return 0;
}