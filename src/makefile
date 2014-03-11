BDIR=../bin
LDIR=../lib

main: main.o LocCounter.o
	g++ $(LDIR)/main.o $(LDIR)/LocCounter.o -std=c++11 -o main

main.o:
	g++ -c main.cpp 
	mv main.o $(LDIR)
	
LocCounter.o:
	g++ -c LocCounter.cpp
	mv LocCounter.o $(LDIR)

clean:
	rm $(LDIR)/*.o
	
install:
	mv main $(BDIR)
	
all: main install