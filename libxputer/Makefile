LXP = libxputer-0.05

clean:
	rm -rf $(LXP)

all: clean
	@echo Extracting original libxputer archive and patching
	mkdir -p $(LXP)
	(cd $(LXP); tar xzvf ../$(LXP).tar.gz)
	(cd $(LXP); patch -p1 < ../$(LXP).parachute.patch)
	@echo Building libxputer
	(cd $(LXP); PATH=$(PARACHUTEPREFIX)/bin:$(PATH); make)

install:
	(cd $(LXP); sudo make install)
