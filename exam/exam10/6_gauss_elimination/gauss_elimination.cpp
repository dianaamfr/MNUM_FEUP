#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector<vector<double>> matrix;
typedef unsigned int row;
typedef unsigned int col;

void row_op(matrix & m, row a, row b, double k) {
  for (col i = 0; i < m[0].size(); i++) {
    m[a][i] -= k* m[b][i];
  }
}

void gauss(matrix & m) {
  for (row i = 0; i < m.size(); i++) {
    row_op(m,i,i,1-1/m[i][i]);
    for (row j = 0; j < m.size(); j++) {
      if(i != j) row_op(m, j, i, m[j][i]);
    }
  }
}

void print_matrix(matrix &m) {
  for (row i = 0; i < m.size(); i++) {
    for (col j = 0; j < m[0].size(); j++) {
      cout << fixed << setprecision(5) << m[i][j] << "   ";
    }
    cout << endl;
  }
}

void estabilidade_externa(matrix & m, double delta){
  double b = delta - delta *(m[0][3] + m[1][3] + m[2][3]);
  m[0][3] = b;
  m[1][3] = b;
  m[2][3] = b;

  gauss(m);

  print_matrix(m);
}

int main() {
  matrix m = {{18.0,-1.0,1.0,0.552949},{3.0,-5.0,4.0,-0.15347},{6.0,8.0,29.0,-0.10655}};

  estabilidade_externa(m,0.1);

  system("pause");
  return 0;
}