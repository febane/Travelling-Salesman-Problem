all: atsp PermGen matriz vetorDePontos tour pilha convexHull trab1 doc

atsp: atsp.c
	gcc -c atsp.c

PermGen: PermGen.c
	gcc -c PermGen.c
	
matriz: matriz.c
	gcc -c matriz.c
	
vetorDePontos: vetorDePontos.c
	gcc -c vetorDePontos.c
	
tour: tour.c
	gcc -c tour.c
	
pilha: pilha.c
	gcc -c pilha.c
	
convexHull: convexHull.c
	gcc -c convexHull.c

trab1: trab.c atsp.o PermGen.o matriz.o vetorDePontos.o tour.o pilha.o convexHull.o
	gcc -o trab1 trab.c atsp.o PermGen.o matriz.o vetorDePontos.o tour.o pilha.o convexHull.o -lm

doc: doc.tex
	latexmk -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make doc.tex

clean:
	rm *.o trab1 doc.pdf doc.log doc.fls doc.aux doc.fdb_latexmk


