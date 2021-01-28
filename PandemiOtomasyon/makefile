VPATH= ./src

hepsi:program calistir

Kisi.o:Kisi.cpp	
	g++ -c -I "./include" -o ./lib/Kisi.o $<

Kontrol.o:Kontrol.cpp	
	g++ -c -I "./include" -o ./lib/Kontrol.o $<

Maske.o:Maske.cpp
	g++ -c -I "./include" -o ./lib/Maske.o $<
	
program:Kisi.o Kontrol.o Maske.o
	g++ -I ./include/ -o ./bin/program ./lib/Kisi.o ./lib/Maske.o ./lib/Kontrol.o ./src/program.cpp
	
calistir:
	./bin/program

