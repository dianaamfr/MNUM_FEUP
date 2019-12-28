#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

double f(double x, double y, double z) {
  return z * y + x;
}

double g(double x, double y, double z) {
  return z * x + y;
}

double f1(double x, double y, double z) {
  return z;
}

double g1(double x, double y, double z) {
  return x - 3 * z - 2 * y;
}

vector<double> sed_euler(double h, double x0, double y0, double z0, double xf) {
  vector<double> v;
  double y = y0;
  double z = z0;
  double ytemp = y;

  for (double x = x0; x < xf; x = x + h) {
    ytemp = y;
    y += h * f(x, y, z);
    z += h * g(x, ytemp, z);
  }

  v.push_back(y);
  v.push_back(z);
  return v;
}

vector<double> sed_rk4(double h, double x0, double y0, double z0, double xf) {
  double y = y0;
  double z = z0;
  vector<double> res;

  for (double x = x0; x < xf; x = x + h) {
    //cout << setw(10) << x << setw(10) << y << setw(10) << f(x, y) << endl;
    double dy1 = h * f(x, y,z);
    double dz1 = h * g(x, y, z);
    double dy2 = h * f(x + h / 2, y + dy1 / 2,z+dz1/2);
    double dz2 = h * g(x + h / 2, y + dy1 / 2, z + dz1 / 2);
    double dy3 = h * f(x + h / 2, y + dy2 / 2, z+ dz2 / 2);
    double dz3 = h * g(x + h / 2, y + dy2 / 2, z + dz2 / 2);
    double dy4 = h * f(x + h, y + dy3,z + dz3);
    double dz4 = h * g(x + h, y + dy3, z + dz3);
    y += dy1 / 6 + dy2 / 3 + dy3 / 3 + dy4 / 6;
    z+= dz1 / 6 + dz2 / 3 + dz3 / 3 + dz4 / 6;
  }
  
  res.push_back(y);
  res.push_back(z);

  return res;
}

vector<double> sed_rk4_1(double h, double x0, double y0, double z0, double xf) {
  double y = y0;
  double z = z0;
  vector<double> res;

  for (double x = x0; x < xf; x = x + h) {
    //cout << setw(10) << x << setw(10) << y << setw(10) << f(x, y) << endl;
    double dy1 = h * f1(x, y, z);
    double dz1 = h * g1(x, y, z);
    double dy2 = h * f1(x + h / 2, y + dy1 / 2, z + dz1 / 2);
    double dz2 = h * g1(x + h / 2, y + dy1 / 2, z + dz1 / 2);
    double dy3 = h * f1(x + h / 2, y + dy2 / 2, z + dz2 / 2);
    double dz3 = h * g1(x + h / 2, y + dy2 / 2, z + dz2 / 2);
    double dy4 = h * f1(x + h, y + dy3, z + dz3);
    double dz4 = h * g1(x + h, y + dy3, z + dz3);
    y += dy1 / 6 + dy2 / 3 + dy3 / 3 + dy4 / 6;
    z += dz1 / 6 + dz2 / 3 + dz3 / 3 + dz4 / 6;
  }

  res.push_back(y);
  res.push_back(z);

  return res;
}

int main() {
  //RK4 para sistemas de eq diferenciais de ordem superior
  
  /*cout << "RK4 para sistemas de eq diferenciais de ordem superior" << endl;
  double sy = sed_rk4(0.1/8, 0, 1, 1, 0.499)[0];
  double sz = sed_rk4(0.1/8, 0, 1, 1, 0.499)[1];
  cout << "Sy = " << sy << endl;
  cout << "Sz = " << sz << endl;
  cout << endl;
  double sy1 = sed_rk4(0.1/16, 0, 1, 1, 0.499)[0];
  double sz1 = sed_rk4(0.1/16, 0, 1, 1, 0.499)[1];
  cout << endl;
  double sy2 = sed_rk4(0.1/32, 0, 1, 1, 0.499)[0];
  double sz2 = sed_rk4(0.1/32, 0, 1, 1, 0.499)[1];
  cout << endl;

  cout << "Qcy = " << (sy1 - sy) / (sy2 - sy1) << endl;
  cout << "Qcz = " << (sz1 - sz) / (sz2 - sz1) << endl;
  cout << "Ey = " << (sy2 - sy1) / 15 << endl;
  cout << "Ez = " << (sz2 - sz1) / 15 << endl;*/

  /*double sy = sed_rk4_1(0.05/2, 0, 0, 0, 0.499)[0];
  double sz = sed_rk4_1(0.05/2, 0, 0, 0, 0.499)[1];
  cout << "Sy = " << sy << endl;
  cout << "Sz = " << sy << endl;
  cout << endl;
  double sy1 = sed_rk4_1(0.05/4, 0, 0, 0, 0.499)[0];
  double sz1 = sed_rk4_1(0.05/4, 0, 0, 0, 0.499)[1];
  cout << endl;
  double sy2 = sed_rk4_1(0.05 / 8, 0, 0, 0, 0.499)[0];
  double sz2 = sed_rk4_1(0.05 / 8, 0, 0, 0, 0.499)[1];
  cout << endl;

  cout << "Qcy = " << (sy1 - sy) / (sy2 - sy1) << endl;
  cout << "Qcz = " << (sz1 - sz) / (sz2 - sz1) << endl;
  cout << "Ey = " << (sy2 - sy1) / 15 << endl;
  cout << "Ez = " << (sz2 - sz1) / 15 << endl;*/


  //EULER para sed de ordem superior
  cout << "Euler para sistemas de eq diferenciais de ordem superior" << endl;
  double sy = sed_euler(0.1 , 0, 1, 1, 0.499)[0];
  double sz = sed_euler(0.1, 0, 1, 1, 0.499)[1];
  cout << "Sy = " << sy << endl;
  cout << "Sz = " << sz << endl;
  cout << endl;
  double sy1 = sed_euler(0.1 / 2, 0, 1, 1, 0.499)[0];
  double sz1 = sed_euler(0.1 / 2, 0, 1, 1, 0.499)[1];
  cout << endl;
  double sy2 = sed_euler(0.1 / 4, 0, 1, 1, 0.499)[0];
  double sz2 = sed_euler(0.1 /4, 0, 1, 1, 0.499)[1];
  cout << endl;

  cout << "Qcy = " << (sy1 - sy) / (sy2 - sy1) << endl;
  cout << "Qcz = " << (sz1 - sz) / (sz2 - sz1) << endl;
  cout << "Ey = " << (sy2 - sy1) / 1 << endl;
  cout << "Ez = " << (sz2 - sz1) / 1 << endl;

  system("pause");
  return 0;
}