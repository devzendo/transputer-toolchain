DIRS=gcc-t800 ttools # libxputer dasm
PARACHUTEPREFIX=/opt/parachute
export PARACHUTEPREFIX

all: setup toolchain

setup:
	@sudo mkdir -p $(PARACHUTEPREFIX)
	@sudo mkdir -p $(PARACHUTEPREFIX)/lib
	@sudo mkdir -p $(PARACHUTEPREFIX)/bin
	@sudo mkdir -p $(PARACHUTEPREFIX)/include
	@sudo mkdir -p $(PARACHUTEPREFIX)/man
	@sudo mkdir -p $(PARACHUTEPREFIX)/info
	# Weird hierarchy, needed for gcc build..?
	@sudo mkdir -p $(PARACHUTEPREFIX)/t800
	@sudo mkdir -p $(PARACHUTEPREFIX)/t800/bin
	@sudo mkdir -p $(PARACHUTEPREFIX)/t800/lib
	@sudo mkdir -p $(PARACHUTEPREFIX)/t800/include

toolchain:
	(cd ttools; make all) || exit 1
	# Create links in weird hierarchy
	(cd $(PARACHUTEPREFIX)/t800/bin; [ -f as ] || ln -s $(PARACHUTEPREFIX)/bin/ast as)
	(cd $(PARACHUTEPREFIX)/t800/bin; [ -f ld ] || ln -s $(PARACHUTEPREFIX)/bin/lit ld)
	(cd $(PARACHUTEPREFIX)/t800/bin; [ -f ar ] || ln -s /usr/bin/ar ar)
	(cd gcc-t800; make all) || exit 1
#	(cd ttools; make install-startups) || exit 1
	# libxputer, dasm... to follow

clean:
	@echo "Making clean in subdirectories..."
	@for i in $(DIRS); do (cd $$i; make clean) || exit 1; done


