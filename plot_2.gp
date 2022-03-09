set title 'Tiempo de equilibrio vs Tamaño'
set xlabel 'Tamaño'; set ylabel 'Pasos hasta tener entropia estable'
set grid
set term pdf; set out 'punto_2.pdf'
#set xrange [16.5:29.5]
#set yrange [10000:80000]
plot 'datos_2.txt' u 2:1 w lp t 'Experimental', 20*(x**2)+18000 w l t 'Teórica: Tiempo=K Tamaño² + C'