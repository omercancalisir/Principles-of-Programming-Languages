derlevecalistir: birlestir calistir

derle:
	
	gcc -I"./include" -c ./src/Rastgele.c -o ./lib/Rastgele.o
	gcc -I"./include" -c ./src/Control.c -o ./lib/Control.o
	gcc -I"./include" -c ./src/IMEINo.c -o ./lib/IMEINo.o
	
	gcc -I"./include" -c ./src/Kisi.c -o ./lib/Kisi.o
	
	gcc -I"./include" -c ./src/RastgeleKisi.c -o ./lib/RastgeleKisi.o
	gcc -I"./include" -c ./src/ReadFile.c -o ./lib/ReadFile.o
	gcc -I"./include" -c ./src/Telefon.c -o ./lib/Telefon.o
	gcc -I"./include" -c ./src/WriteFile.c -o ./lib/WriteFile.o
	gcc -I"./include" -c ./src/KimlikNo.c -o ./lib/KimlikNo.o
	gcc -I"./include" -c ./src/Main.c -o ./lib/Main.o

birlestir: derle
	g++ ./lib/Control.o ./lib/IMEINo.o ./lib/KimlikNo.o ./lib/Kisi.o ./lib/Rastgele.o \
	 	./lib/RastgeleKisi.o ./lib/ReadFile.o ./lib/Telefon.o ./lib/WriteFile.o ./lib/Main.o -o ./bin/program.exe


calistir:
	./bin/program.exe