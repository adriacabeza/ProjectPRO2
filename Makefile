OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o individu.o poblacio.o especie.o arbregenealogic.o
		g++ -o program.exe program.o especie.o individu.o poblacio.o arbregenealogic.o

program.o:  program.cc especie.hh poblacio.hh individu.hh arbregenealogic.hh
	g++ -c program.cc $(OPCIONS)

especie.o:  especie.cc especie.hh
	g++ -c especie.cc $(OPCIONS)

individu.o: individu.cc especie.hh individu.hh
	g++ -c individu.cc $(OPCIONS)

poblacio.o: poblacio.cc individu.hh poblacio.hh especie.hh Arbre.hh
	g++ -c poblacio.cc $(OPCIONS)

arbregenealogic.o: arbregenealogic.cc Arbre.hh poblacio.hh individu.hh
	g++ -c arbregenealogic.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
test:
	./program.exe <jpub.in >jpubmeu.out diff -bB jpub.out jpubmeu.out

jutge:
	tar -cvf practica.tar individu.hh individu.cc program.cc poblacio.hh poblacio.cc especie.cc html.zip especie.hh arbregenealogic.cc Makefile arbregenealogic.hh
