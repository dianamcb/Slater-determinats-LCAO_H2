Tabla1.exe: fuente.o tabla.o
	g++ -std=c++17 *.o -o Tabla1.exe

fuente.o: H2-HF.cpp H2-HF.h
	g++ -std=c++17 H2-HF.cpp -c -o fuente.o

tabla.o: tabla.cpp
	g++ -std=c++17 tabla.cpp -c -o tabla.o

.PHONY: clean
clean: 
	rm *.o Tabla1.exe
