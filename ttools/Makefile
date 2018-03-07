TT = ttools-2.0beta2

clean:
	rm -rf $(TT)

all: clean
    mkdir $(TT)
	@echo Extracting original TTOOLS archive and patching
	tar xzf $(TT).tar.gz
	(cd $(TT); patch -p1 < ../$(TT).parachute.patch)
	@echo Building TTOOLS

install:
	(cd $(TT); make; sudo make install)
