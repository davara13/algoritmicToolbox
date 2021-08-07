#include <iostream>

int get_change(int m) {
  int n;
  int resto = m%10;
  m = m - resto;
  n  = m / 10;
  if(resto>=5){
  	n = n + 1 + resto - 5;
  }else{
  	n = n + resto;
  }
  return n;
  
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
