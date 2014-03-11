SDIR=../src
BDIR=../bin
LDIR=../lib

test: test_main.o
	g++ $(LDIR)/test_main.o $(LDIR)/LocCounter.o -std=c++11 -o test_main
	
test_main.o:
	g++ -c test_main.cpp -I$(SDIR)
	mv test_main.o $(LDIR)
	
install:
	mv test_main $(BDIR)

#jew comment	
all: test install
