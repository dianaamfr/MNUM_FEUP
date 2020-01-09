#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector<vector<double>> matrix;
typedef unsigned int row;
typedef unsigned int col;

void row_op(matrix& m, row a, row b, double k){
  for (col i = 0; i < m[0].size(); i++) {
    m[a][i] -= k * m[b][i];
  }
}

void gauss(matrix & m) {
  for (row i = 0; i < m.size(); i++) {
    row_op(m,i,i,1-1/m[i][i]);
    for (row j = 0; j < m.size(); j++) {
      if (i != j) row_op(m,j,i,m[j][i]);
    }
  }
}

void gauss_diagonal(matrix& m) {
  for (row i = 0; i < m.size(); i++) {
    row_op(m, i, i, 1 - 1 / m[i][i]);
    for (row j = 0; j < m.size(); j++) {
      if (i < j) row_op(m, j, i, m[j][i]);
    }
  }
}

void print_matrix(matrix m) {
  for (row i = 0; i < m.size(); i++) {
    for (col j = 0; j < m[0].size(); j++) {
      cout << setprecision(6) << fixed <<m[i][j] << "    ";
    }
    cout << endl;
  }
}

void gauss_stability(matrix & unsol, matrix & sol, double da, double db) {
  double b = db - da*(sol[0][4]+sol[1][4]+ sol[2][4]+sol[3][4]);
  unsol[0][4] = b;
  unsol[1][4] = b;
  unsol[2][4] = b;
  unsol[3][4] = b;
  gauss(unsol);
}

int main() {
  matrix m = { {0.1,0.5,3.0,0.25,0.0},{1.2,0.2,0.25,0.2,1.0},{-1.0,0.25,0.3,2.0,2.0},{2.0,0.00001,1.0,0.4,3.0} };
  matrix unsol = m;
  gauss_diagonal(m);
  print_matrix(m);
  cout << endl;

  gauss(m);
  print_matrix(m);
  cout << endl;

  gauss_stability(unsol,m,0.5,0.5);
  print_matrix(unsol);
  cout << endl;

  system("pause");
  return 0;
}
