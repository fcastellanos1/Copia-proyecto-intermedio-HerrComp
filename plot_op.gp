set title 'Optimizaciones para cada tamaño'
set xlabel 'Tamaño de la malla'; set ylabel 'Tiempo de la optimización [s]'
set grid
set term pdf; set out 'optimizacion.pdf'
plot 'optimizacion.txt' u 1:2 w l t 'Sin optimización', \
     'optimizacion.txt' u 1:3 w l t 'Optimizacion -O3'
     