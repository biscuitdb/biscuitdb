#include "main/biscuit.h"
using std::cout;

void biscuit::Hello() { cout << "Hello from biscuit db.\n"; }

int biscuit::Radd(int x, int y) {
  for (int i = 0; i < y; i++) {
    x++;
  }
  return x;
}
