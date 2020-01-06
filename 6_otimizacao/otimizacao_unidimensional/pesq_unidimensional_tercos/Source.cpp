#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double f(double x) {
  return sin(x);;
}

vector<double> pesquisa_unidimensional(double guess, double step, double precision) {
  //verificar para que lado a fun��o decresce
  if (f(guess) < f(guess + step)) step = -step;

  //guardar dois passos anteriores
  double x0 = guess;
  double x1 = x0 + step;
  double x2 = x0 + 2 * step;

  while (abs(x2-x1)>precision) {

    //se estivermos a deslocar-nos no sentido decrescente da fun��o damos mais um passo
    if (f(x1) > f(x2)) {
      x0 = x1;
      x1 = x2;
      x2 = x1 + step;
    }
    //se dermos um passo que nos faz come�ar a deslocar-nos no sentido crescente do gr�fico
    //da fun��o recuamos um passo, diminuimos o passo e voltamos a repetir o processo com o novo passo 
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

void tercos(double x1, double x2, double precision) {

  double x3, x4, dist;

  while (abs(x2-x1)>precision){
    dist = abs(x2 - x1) / 3.0; //tamanho do ter�o
    x3 = x1 + dist;
    x4 = x1 + 2 * dist;

    if (f(x4) < f(x3)) // o m�nimo pertence a [x3,x2]
      x1 = x3;
    else // o m�nimo pertence a [x1,x4]
      x2 = x4;
  }

  //imprimir os 3 valores de x e respetivo y do �ltimo intervalo calculado que cont�m a ra�z

  if (x1 == x3) {
    cout << "x3 = " << x3 << "    " << "f(x3) = " << f(x3) << endl;
    cout << "x4 = " << x4 << "    " << "f(x4) = " << f(x4) << endl;
    cout << "x2 = " << x2 << "    " << "f(x2) = " << f(x2) << endl;
  }
  else {
    cout << "x1 = " << x1 << "    " << "f(x1) = " << f(x1) << endl;
    cout << "x3 = " << x3 << "    " << "f(x3) = " << f(x3) << endl;
    cout << "x4 = " << x4 << "    " << "f(x4) = " << f(x4) << endl;
  }
}

int main() {

  double guess = 2, step = 0.1, precision = pow(10,-5);

  //Usando a pesquisa unidimensional
  /*vector<double> valoresDaPesquisa = pesquisa_unidimensional(guess, step,precision);
  tercos(valoresDaPesquisa[0], valoresDaPesquisa[2],precision);*/

  //aplicando apenas o m�todo dos ter�os
  double x1 = 3.5, x2 = 6;
  tercos(x1,x2,precision);

  system("pause");
  return 0;
}