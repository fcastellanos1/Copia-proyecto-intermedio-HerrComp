#include "funciones.h"

int main(void)
{
  int SIZE = 50; //poner 20
  int N = 50; //poner 400
  int seed = 0;
  int time = 0;
  int pasos_max = 100000;
  
  int hueco = 5;


  Eigen::MatrixXi M = creacion_matrix(SIZE, N);
  Eigen::MatrixXi P = creacion_posiciones(M, N);
  
  
  for(int ii=1; ii<= pasos_max; ii++){
    
    step_2(M, P, time, seed);
    
    std::cout << time << "\t" << P.rows() << "\t" << std::exp(-time/10000) << "\n";
    
    for (int jj=1; jj < P.rows(); jj++){
      if( P(jj, 0) == SIZE-1 && P(jj,1) < hueco + SIZE/2 && P(jj,1) > SIZE/2 - hueco){
        
        remover(P,jj);
        break;
        
      }  
    }
  }

  return 0;
}































