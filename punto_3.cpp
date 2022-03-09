#include "funciones.h"

int main(void)
{
  int SIZE = 100; //poner 20
  int N = 100; //poner 400
  int seed = 0;
  int time = 0;
  int pasos_max = 10000;
  
  
  Eigen::MatrixXi M = creacion_matrix(SIZE, N);
  Eigen::MatrixXi P = creacion_posiciones(M, N);
  
  
  for(int ii=1; ii<= pasos_max; ii++){
    
    step_2(M, P, time, seed);
    
    std::cout << time << "\t" << calcular_tamano(M,P,N) << "\t" << std::sqrt(time) << "\n";
    
  }
  return 0;
}














