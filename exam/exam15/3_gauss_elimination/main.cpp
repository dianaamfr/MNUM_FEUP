#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<vector<double>> matrix;
typedef unsigned int col;
typedef unsigned int row;

/* Ra = Ra - k* Rb  */
void rowop(matrix & m, row a, row b, double k) {
  for (col i = 0; i < m[0].size(); i++) {
    m[a][i] -= k * m[b][i];
  }
}

//a
void gauss(matrix & m) {
  for (row i = 0; i < m.size(); i++) {
    rowop(m,i,i,1-1/m[i][i]);
    for (row j = 0; j < m.size(); j++) {
      if(i != j)
        rowop(m, j, i, m[j][i]);
    }
  }
}

//b
void gauss_diagonal(matrix& m) {
  for (row i = 0; i < m.size(); i++) {
    rowop(m, i, i, 1 - 1 / m[i][i]);
    for (row j = 0; j < m.size(); j++) {
      if (i < j)
        rowop(m, j, i, m[j][i]);
    }
  }
}

//c
void gauss_estabilidade_externa_diagonal(double da, double db) {
  matrix m = { {1.0,1 / 2.0,1 / 3.0,db - 3 * da},{1 / 2.0,1 / 3.0,1 / 4.0,db - 3 * da},{1 / 3.0,1 / 4.0,1 / 5.0,db - 3 * da} };
  
  gauss_diagonal(m);
  for (row i = 0; i < m.size(); i++) {
    for (col j = 0; j < m[0].size(); j++) {
      cout << m[i][j] << "  ";
    }
    cout << "\n";
  }
}

//d
void gauss_estabilidade_externa(matrix m, double da, double db){
  double b = db - da * (m[0][3] + m[1][3] + m[2][3]);
  matrix e = { {1.0,1 / 2.0,1 / 3.0,b},{1 / 2.0,1 / 3.0,1 / 4.0,b},{1 / 3.0,1 / 4.0,1 / 5.0,b} };
  gauss(e);

  for (row i = 0; i < e.size(); i++) {
    for (col j = 0; j < e[0].size(); j++) {
      cout << e[i][j] << "  ";
    }
    cout << "\n";
  }
}



int main() {
  matrix m = { {1.0,1 / 2.0,1 / 3.0,-1.0},{1 / 2.0,1 / 3.0,1 / 4.0,1.0},{1/3.0,1/4.0,1/5.0,1.0}};
  gauss_diagonal(m);
  cout << "(a)Matriz diagonal superior\n";
  for (row i = 0; i < m.size(); i++) {
    for (col j = 0; j < m[0].size(); j++) {
      cout << m[i][j]<< "  ";
    }
    cout << "\n";
  }
  cout << endl;

  gauss(m);
  cout << "(b)Resultado pela eliminacao de Gauss\n";
  for (row i = 0; i < m.size(); i++) {
    for (col j = 0; j < m[0].size(); j++) {
      cout << m[i][j] << "  ";
    }
    cout << "\n";
  }
  cout << "\n(c)Estabilidade - matriz diagonal superior\n";
  gauss_estabilidade_externa_diagonal(0.05,0.05);

  cout << "\n(c)Estabilidade - resultado\n";
  gauss_estabilidade_externa(m,0.05, 0.05);

  system("pause");
  return 0;
}