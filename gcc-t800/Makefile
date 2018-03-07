G272 = gcc-2.7.2

clean:
	rm -rf $(G272)

all: clean
	@echo Extracting original GCC 2.7.2 archive and patching
	tar xzf $(G272).tar.gz
	(cd $(G272); patch -p1 < ../$(G272)-t800.12.diff)       # The patches against gcc to add Transputer support
	(cd $(G272); patch -p1 < ../$(G272)-t800.parachute.patch) # To build on modern Linux etc.
	@echo Configuring GCC 2.7.2-T800
	(cd $(G272); ./configure --target=t800 --prefix=$(PARACHUTEPREFIX))
	@echo Building GCC 2.7.2-T800
	(cd $(G272); make LANGUAGES='c c++' CC=gcc)

install:
	(cd $(G272); sudo make install)
