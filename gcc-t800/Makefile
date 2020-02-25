G272 = gcc-2.7.2

clean:
	(cd $(G272); if [ -f Makefile ]; then make clean; fi )

all:
	@echo Configuring GCC 2.7.2-T800 in $(PARACHUTEPREFIX)
	(cd $(G272); ./configure --target=t800 --prefix=$(PARACHUTEPREFIX))
	@echo Building GCC 2.7.2-T800
	(cd $(G272); make LANGUAGES='c' CC=gcc)
#	(cd $(G272); export PATH="$(PARACHUTEPREFIX)/bin:$(PATH)"; env; make LANGUAGES='c' CC=gcc)
#	(cd $(G272); make LANGUAGES='c c++' CC=gcc)
	(cd $(G272); sudo make install)
