#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

float f(float x) {
  if (x == (float)0) return 0.36;
  else if (x == (float)0.25) return 1.19;
  else if (x == (float)0.5) return 1.32;
  else if (x == (float)0.75) return 0.21;
  else if (x == (float)1) return 1.15;
  else if (x == (float)1.25) return 1.39;
  else if (x == (float)1.5) return 0.12;
  else if (x == (float)1.75) return 1.22;
  else if (x == (float)2) return 0.6;
  else cout << "ERROR\n";
}

float simpson(float x0, float xf, float h){

  int n = (xf - x0) / h;
  float s = f(x0) + f(xf);
  int i;

  for (i = 1; i < n; i++){
    if(i%2 == 0)
      s+= 2*f(x0 + i*h);
    else
      s += 4 * f(x0 + i * h);
  }

    s = (h / 3) * s;
    return s;
}

int main() {
  
  float sll = simpson(0,2,0.25);

  cout << sll << endl;
  float sl = simpson(0, 2, 0.25*2.0);
  float s = simpson(0, 2, 0.25*4.0);

  cout << "e = " << (sll - sl) / 15;

  system("pause");
  return 0;
}
