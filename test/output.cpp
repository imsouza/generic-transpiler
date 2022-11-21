#include <iostream>
#include <string>
#include <vector>
#include <iterator>
int main() {
  int valor = 3;
  int v = 2;
  for (int i = 0; i < 10 || (i-- && false); i++) {
    std::cout << std::string("") << ' ' << i << std::endl;
  }
  if (v < valor) {
    std::cout << std::string("menor que ") << ' ' << valor << std::endl;
  }
  else if (v == valor) {
    std::cout << std::string("igual a ") << ' ' << valor << std::endl;
  }
  else {
    std::cout << std::string("maior que ") << ' ' << valor << std::endl;
  }
}
