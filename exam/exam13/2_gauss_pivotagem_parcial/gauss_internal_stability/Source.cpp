#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<vector<double>> matrix;

void internal_stabilty(matrix & m, vector<double> &sol) {
  double s = 0;
  for (unsigned int i = 0; i < m.size(); i++){
    s = 0;
    for (unsigned int j = 0; j < m[0].size(); j++) {
      if (j < m[0].size() - 1) {
        s += m[i][j] * sol[j];
      }
      else
        s -= m[i][j];
    }
    cout << abs(s) << endl;
  }
}

int main() {
  matrix m = { {0.00001,2.00000,5.00000,200.00000},{1.00000,-0.20000,1.00000,4.00000},{3.00000,0.50000,-4.00000,2.00000} };
  double x1 = 3.0;
  double x2 = 73.33331;
  double x3 = 10.66667;
  vector<double> solution;
  solution.push_back(x1);
  solution.push_back(x2);
  solution.push_back(x3);
  internal_stabilty(m,solution);
  x1 = 5.53846;
  x2 = 69.23076;
  x3 = 12.30769;
  solution.clear();
  solution.push_back(x1);
  solution.push_back(x2);
  solution.push_back(x3);
  cout << endl;
  internal_stabilty(m, solution);
  system("pause");
  return 0;
}