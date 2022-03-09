#include "funciones.h"

int main(void)
{
  int SIZE = 20;
  int N = 400;
  int seed = 1;
  int time = 0;
  int pasos_max = 1000000;

  Eigen::MatrixXi M; //Se tienen que inicializar afuera del for
  Eigen::MatrixXi P; //para luego cambiar de tamaño dentro.
  double precision_entropia = 0.3;
  int delta_tiempo = 1000;
  int repeticiones_delta = 20;
  
  
  for(int size_temp = SIZE/2; size_temp<= 2*SIZE; size_temp++){
    time = 0;
    M = creacion_matrix(size_temp, N); //Matriz de casillas
    P = creacion_posiciones(M, N); //Matriz de posiciones
    
    tiempo_equilibrio(time, M, P, seed, pasos_max, precision_entropia, delta_tiempo, repeticiones_delta);
    
    std::cout<<time<<"\t"<<size_temp<<"\n";
  }
  
  return 0;
}
