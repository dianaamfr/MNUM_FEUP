#include <cmath>
#include <iostream>
using namespace std;

double B=(sqrt(5)-1)/2.0;
double A= pow(B,2);

double f(double x){
  return 5*cos(x)-sin(x);
}

void aurea(double x1, double x2){
  double x3=x1 + A*(x2-x1) ;
  double x4= x1 + B*(x2-x1);
}

int main() {
  double x1 = 2, x2=4; 
  aurea(x1,x2,2);

  system("pause");
  return 0;
}
