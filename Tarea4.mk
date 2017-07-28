# MakeFile para la tarea 4.

PuntoNemo.pdf : Plots.py datos.txt
	python Plots.py

datos.txt : GeographicPoint.x
	./GeographicPoint.x

GeographicPoint.x : GeographicPoint.c
	cc GeographicPoint.c -o GeographicPoint.x -lm

clean :
	rm datos.txt *.pdf *.x
