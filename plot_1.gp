set title 'Entropía vs Tiempo'
set xlabel 'Número de pasos'; set ylabel 'Entropía'
set grid
set term pdf; set out 'punto_1.pdf'
plot 'datos_1.txt' u 1:2 w lp t 'Entropía'