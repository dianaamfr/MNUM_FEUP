#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

float f1(float x) {

  if (x == 0) return 1.04;
  else if (x == 0.25) return 0.37;
  else if (x == 0.5) return 0.38;
  else if (x == 0.75) return 1.49;
  else if (x == 1) return 1.08;
  else if (x == 1.25) return 0.13;
  else if (x == 1.5) return 0.64;
  else if (x == 1.75) return 0.84;
  else if (x == 2) return 0.12;
}

float simpson(float a, float b, float h) {
  float s = f1(a) + f1(b);
  float n = (b - a) / h;

  for (unsigned int i = 1; i < n; i++) {
    if (i % 2 == 0)
      s += 2 * f1(a + i * h);
    else
      s += 4 * f1(a + i * h);
  }

  return h * s / 3;
}

int main() {

  float s = simpson(0, 2, 1);
  float sl = simpson(0, 2, 0.5);
  float sll = simpson(0, 2, 0.25);

  cout << "s = " << s << endl;
  cout << "s' = " << sl << endl;
  cout << "s'' = " << sll << endl;
  float e = (sll - sl)/15;
  cout << "e = " << e;

  system("pause");
  return 0;
}