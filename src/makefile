BDIR=../bin
LDIR=../lib

main: main.o LocCounter.o
	g++ $(LDIR)/main.o $(LDIR)/LocCounter.o -std=c++11 -o main

main.o:
	g++ -c main.cpp -o $(LDIR)/$@ 
	
LocCounter.o:
	g++ -c LocCounter.cpp -o $(LDIR)/$@ 

clean:
	rm $(LDIR)/*.o
	
install:
	mv main $(BDIR)
	
all: main install