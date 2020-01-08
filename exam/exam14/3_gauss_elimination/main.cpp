#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector<vector<double>> matrix;
typedef unsigned int row;
typedef unsigned int col;

void row_op(matrix& m, row a, row b, double k) {
  for (col i = 0; i < m[0].size(); i++) {
    m[a][i] -= k * m[b][i];
  }
}

void gauss(matrix & m) {
  for (row i = 0; i < m.size(); i++) {
    row_op(m,i,i, 1- 1/m[i][i]);
    for (row j = 0; j < m.size(); j++) {
      if (i != j) row_op(m,j,i,m[j][i]);
    }
  }
}

void triangular(matrix & m) {
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
      cout << setprecision(5) << fixed << m[i][j] << "    ";
    }
    cout << "\n";
  }
}

int main() {
  matrix m = { {0.1,0.5,3,0.25,0.0},{1.2,0.2,0.25,0.2,1.0},{-1.0,0.25,0.3,2.0,2.0},{2.0,0.00001,1.0,0.4,3.0} };

  cout << "(a)\n";
  triangular(m);
  print_matrix(m);
  cout << endl;

  cout << "(b)\n";
  gauss(m);
  print_matrix(m);
  cout << endl;

  double da = 0.3;
  double db = da;
  double b1 = db - da * m[0][4];
  for (row i = 0; i < m.size() - 1; i++) {
    
  }
  double b = db - da *(m[0][4] + m[1][4] + m[2][4] + m[3][4]);
  matrix e = { {0.1,0.5,3,0.25,b},{1.2,0.2,0.25,0.2,b},{-1.0,0.25,0.3,2.0,b},{2.0,0.00001,1.0,0.4,b} };

  cout << "(c)\n";
  gauss(e);
  print_matrix(e);
  cout << endl;
}