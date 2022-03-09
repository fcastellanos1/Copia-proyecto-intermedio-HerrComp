set title 'Tamaño de gota vs Tiempo'
set xlabel 'Número de pasos'; set ylabel 'Tamaño de gota'
set grid
set yrange[0:12]
set term pdf; set out 'punto_3.pdf'
plot 'datos_3.txt' u 1:2 w lp t 'Experimental', 0.1*sqrt(x) w l t 'Teórica: Tamaño= K*sqrt(x)'