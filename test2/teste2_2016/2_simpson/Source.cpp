#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
  if (x == 0) return 0.18;
  else if (x == (double)0.2) return 0.91;
  else if (x == (double)0.4) return 0.83;
  else if (x == (double)0.6) return 1.23;
  else if (x == (double)0.8) return 0.88;
  else if (x == (double)1) return 1.37;
  else if (x == (double)1.2) return 0.8;
  else if (x == (double)1.4) return 1.34;
  else if (x == (double)1.6) return 0.43;
  else cout << "ERROR"<<endl;
}

double simpson(double a, double b, double h) {
  int n = (b-a) / h;

  double s = f(a) + f(b);

  for (int i = 1; i < n; i++) {
    if(i % 2 == 0)
      s += 2 * f(a + i * h);
    else
      s += 4 * f(a + i * h);
  }

  s = s * (h/3);

  cout << "S = " << s << endl;
  return s;
}

int main() {

  double s = simpson(0, 1.6, 0.8);
  double sl = simpson(0, 1.6, 0.4);
  double sll = simpson(0, 1.6, 0.2);

  cout << "E = " << (sll - sl) / 15 << endl;

  system("pause");
  return 0;
}