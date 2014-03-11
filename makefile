BDIR=./bin
LDIR=./lib

all: main_all test_all

main_all:
	(cd src && make && make install)

main:
	(cd src && make)
	
install:
	(cd src && make install)
	
test_all:
	(cd test && make && make install)
	
mytest:
	(cd test && make)
	
install_test:
	(cd test && make install)
	
clean:
	rm $(LDIR)/*.o
	
clean_all: clean
	rm $(BDIR)/*