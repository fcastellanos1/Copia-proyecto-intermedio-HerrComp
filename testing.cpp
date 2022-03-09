#include "funciones.h"

int main(void)
{
  //Test para ver si la distribución es equitativa:
  int semillita = 1;
  test_aleatorio(semillita, 0, 9);
  std::cout<<"New limits: \n";
  test_aleatorio(semillita, 2, 5);
  std::cout<<"\n";

  
  return 0;
}
