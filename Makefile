DIRS=gcc-t800 # libxputer dasm ttools
PARACHUTEPREFIX=/opt/parachute

all: setup toolchain

setup:
	@sudo mkdir -p $(PARACHUTEPREFIX)
	@sudo mkdir -p $(PARACHUTEPREFIX)/lib
	@sudo mkdir -p $(PARACHUTEPREFIX)/bin
	@sudo mkdir -p $(PARACHUTEPREFIX)/include
	@sudo mkdir -p $(PARACHUTEPREFIX)/man
	@sudo mkdir -p $(PARACHUTEPREFIX)/info

toolchain:
	@echo "Making all in subdirectories..."
	@for i in $(DIRS); do (cd $$i; make all) || exit 1; done

install:
	@echo "Making install in subdirectories..."
	@for i in $(DIRS); do (cd $$i; make clean) || exit 1; done

clean:
	@echo "Making clean in subdirectories..."
	@for i in $(DIRS); do (cd $$i; make clean) || exit 1; done


