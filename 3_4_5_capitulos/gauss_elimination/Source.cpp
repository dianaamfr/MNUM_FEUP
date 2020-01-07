#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<vector<double> > matrix;
typedef unsigned int col;
typedef unsigned int row;

void internal_stability(matrix m, matrix r) {
  for (row i = 0; i < m.size(); i++) {
    double s = 0;
    for (col j = 0; j < m[0].size(); j++) {
      if (j != m[0].size() - 1)
        s += m[i][j] * r[j][r[0].size() - 1];
      else
        s -= m[i][j];
    }
    cout << s << endl;
  }
}

// row a = row a - row b * k 
void rowop(matrix& m, row a, row b, double k) {
  for (col i = 0; i < m[0].size(); i++) {
    m[a][i] -= k * m[b][i];
  }
}

void gauss_elimination(matrix& m) {
  for (row i = 0; i < m.size(); i++) {
    rowop(m, i, i, 1 - 1 / m[i][i]);
    for (row j = 0; j < m.size(); j++) {
      if (i != j) rowop(m, j, i, m[j][i]);
    }
  }
}

int main() {

  matrix m = { {0.7,2,3,12},{-6,0.45,-0.25,15},{8,-1.1,1.05,23} };
  matrix r = m;

  gauss_elimination(r);

  for (row i = 0; i < r.size(); i++) {
    for (col j = 0; j < r[0].size(); j++) {
      cout << r[i][j] << "  ";
    }
    cout << "\n";
  }

  cout << endl;
  internal_stability(m, r);
  //external_stability(); //(to do)

  system("pause");
  return 0;
}