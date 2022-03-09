all: punto_1.cpp punto_2.cpp punto_3.cpp punto_4.cpp funciones.cpp funciones.h plot_1.gp plot_2.gp plot_3.gp plot_4.gp
	parallel 'g++ -O3 -fsanitize=undefined -fsanitize=leak -fsanitize=address -std=c++11  punto_{}.cpp funciones.cpp -o punto_{}.out' ::: $$(seq 1 4)
	parallel './punto_{}.out > datos_{}.txt' ::: $$(seq 1 4)
	parallel 'gnuplot plot_{}.gp' ::: $$(seq 1 4)

punto_3.pdf: plot_3.gp datos_3.txt
	gnuplot $<

datos_3.txt: punto_3.out
	./$< > $@

punto_3.out: punto_3.cpp funciones.cpp funciones.h
	g++ -g -pg $< funciones.cpp -o $@

punto_2.pdf: plot_2.gp datos_2.txt
	gnuplot $<

datos_2.txt: punto_2.out
	./$< > $@

punto_2.out: punto_2.cpp funciones.cpp funciones.h
	g++ -g -pg $< funciones.cpp -o $@

punto_1.pdf: plot_1.gp datos_1.txt
	gnuplot $<

datos_1.txt: punto_1.out
	./$< > $@

punto_1.out: punto_1.cpp funciones.cpp funciones.h
	g++ -g -pg $< funciones.cpp -o punto_1.out

gprof: report_gprof.txt

gprof-report.txt: punto_1.cpp funciones.cpp
	g++ -g -pg $< funciones.cpp -o report.x
	./report.x
	gprof ./report.x gmon.out > $@

report: informe.tex
	pdflatex informe

optimizacion: plot_op.gp optimizacion.txt
	gnuplot $<

test: testing.cpp funciones.cpp funciones.h
	g++ testing.cpp funciones.cpp -o testing.out
	./testing.out

clean:
	rm -rf *.x *.out *.x.* *~ *.pdf *.png *.txt *.data
