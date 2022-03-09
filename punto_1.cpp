#include "funciones.h"

int main(void)
{
  int SIZE = 20;
  int N = 400;
  int seed = 0;
  int time = 0;
  int pasos_max = 100000;
  
  
  Eigen::MatrixXi M = creacion_matrix(SIZE, N); //Matriz de casillas
  Eigen::MatrixXi P = creacion_posiciones(M, N); //Matriz de posiciones

  std::cout<<time<<"\t"<<calcular_entropia_3(M, N)<<"\n";
  for(int ii=1; ii<= pasos_max; ii++){
    step_2(M, P, time, seed);
    std::cout<<time<<"\t"<<calcular_entropia_3(M, N)<<"\n";
  }
  
  return 0;
}
