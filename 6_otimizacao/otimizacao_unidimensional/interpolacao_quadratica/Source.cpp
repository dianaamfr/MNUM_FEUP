#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double f(double x) {
  return sin(x);
}

vector<double> pesquisa_unidimensional(double guess, double step, double precision) {
  //verificar para que lado a função decresce
  if (f(guess) < f(guess + step)) step = -step;

  //guardar dois passos anteriores
  double x0 = guess;
  double x1 = x0 + step;
  double x2 = x0 + 2 * step;

  while (abs(x2 - x1) > precision) {

    //se estivermos a deslocar-nos no sentido decrescente da função damos mais um passo
    if (f(x1) > f(x2)) {
      x0 = x1;
      x1 = x2;
      x2 = x1 + step;
    }
    //se dermos um passo que nos faz começar a deslocar-nos no sentido crescente do gráfico
    //da função recuamos um passo, diminuimos o passo e voltamos a repetir o processo com o novo passo 
    else {
      step /= 2;
      x1 = x0 + step;
      x2 = x0 + 2 * step;
    }
  }

  vector<double> result;
  result.push_back(x0);
  result.push_back(x1);
  result.push_back(x2);

  return result;
}

void interpolacao_quadratica(double guess, double step, double precision,double precisionSearch) {
  double guessAnt, x1, x2, x3;
  vector<double> valoresDaPesquisa;

  do {
    guessAnt = guess;
    valoresDaPesquisa = pesquisa_unidimensional(guess, step, precisionSearch);
    x1 = valoresDaPesquisa[0];
    x2 = valoresDaPesquisa[1];
    x3 = valoresDaPesquisa[2];
    guess = x2 + (x2 - x1) * (f(x1) - f(x3)) / (2 * (f(x3) - 2 * f(x2) + f(x1)));
  } while (abs(guess - guessAnt) > precision);

  cout << guess;
}

int main() {
  double guess = 2, step = 0.1, precision1 = 0.01, precision2 = pow(10, -6);

  //com pesquisa iterativa (incluida no algoritmo) - cada vez que se descobre a nova estimativa para o mínimo
  interpolacao_quadratica(guess,step,precision1,precision2); 

  system("pause");
  return 0;
}