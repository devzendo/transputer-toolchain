G272 = gcc-2.7.2

clean:
	(cd $(G272); make clean)

all:
	@echo Configuring GCC 2.7.2-T800
	(cd $(G272); ./configure --target=t800 --prefix=$(PARACHUTEPREFIX))
	@echo Building GCC 2.7.2-T800
	(cd $(G272); make LANGUAGES='c c++' CC=gcc)

install:
	(cd $(G272); sudo make install)
