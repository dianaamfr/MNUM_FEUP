#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x, double y) {
  return pow(x, 2) + pow(y, 2);
}

double euler(double h, double x0, double y0,double xf) {
  double y = y0;
  for (double x = x0; x < xf; x = x + h) {
    cout << setw(10) << x << setw(10) << y << setw(10) << f(x, y) << endl;
    y += h * f(x, y);
  }
  return y;
}

double rungeKutta(float h, float x0, float y0, float xf) {
  float y = y0;
  for (float x = x0; x < xf; x = x + h) {
    cout << setw(10) << x << setw(10) << y << setw(10) << f(x, y) << endl;
    double xtmp = x + h / 2;
    double ytmp = y + (h / 2) * f(x,y);
    y += h * f(xtmp, ytmp);
  }
  return y;
}

double rungeKutta4(double h, float x0, float y0, float xf) {
  double y = y0;
  for (double x = x0; x < xf; x = x + h) {
    //cout << setw(10) << x << setw(10) << y << setw(10) << f(x, y) << endl;
    double d1 = h*f(x,y);
    double d2 = h * f(x+h/2, y+d1/2);
    double d3 = h * f(x + h / 2, y + d2 / 2);
    double d4 = h * f(x + h, y + d3);
    y += d1/6+d2/3+d3/3+d4/6;
  }
  return y;
}

int main() {

  //EULER
  /*double s = euler(0.1,0,0, 1.39);
  cout << endl;
  cout << "S = " << s << endl;
  double s1 = euler(0.05,0,0, 1.39);
  cout << endl;
  cout << "S' = " << s1 << endl;
  double s2 = euler(0.025,0,0, 1.39);
  cout << endl;
  cout << "S'' = " << s2 << endl;
  cout << "Qc = " << (s1 - s) / (s2 - s1) << endl;
  cout << "E = " << (s2 - s1) << endl;
  cout << endl;*/

 //RUNGE KUTTA
  double s = rungeKutta4(0.0125, 0, 0, 1.3999);
  cout << endl;
  cout << "S = " << s << endl;
  double s1 = rungeKutta4(0.0125/2, 0, 0, 1.3999);
  cout << endl;
  cout << "S' = " << s1 << endl;
  double s2 = rungeKutta4(0.0125/4, 0, 0, 1.3999);
  cout << endl;
  cout << "S'' = " << s2 << endl;
  cout << "Qc = " << (s1 - s) / (s2 - s1) << endl;
  cout << "E = " << (s2 - s1) / 15 << endl;
  cout << endl;

  system("pause");
  return 0;
}