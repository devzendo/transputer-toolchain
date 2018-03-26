DIRS=gcc-t800 ttools # libxputer dasm
PARACHUTEPREFIX=/opt/parachute
export PARACHUTEPREFIX

OWNER=${USER:=$(/usr/bin/id -run)}

all: setup toolchain

setup:
	@sudo mkdir -p $(PARACHUTEPREFIX)
	@sudo chown $(OWNER):$(OWNER) $(PARACHUTEPREFIX)
	mkdir -p $(PARACHUTEPREFIX)/lib
	mkdir -p $(PARACHUTEPREFIX)/bin
	mkdir -p $(PARACHUTEPREFIX)/include
	mkdir -p $(PARACHUTEPREFIX)/man
	mkdir -p $(PARACHUTEPREFIX)/info
	# Weird hierarchy, needed for gcc build..?
	mkdir -p $(PARACHUTEPREFIX)/t800
	mkdir -p $(PARACHUTEPREFIX)/t800/bin
	mkdir -p $(PARACHUTEPREFIX)/t800/lib
	mkdir -p $(PARACHUTEPREFIX)/t800/include

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


