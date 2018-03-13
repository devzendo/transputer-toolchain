TT = ttools-2.0beta2

clean:
	(cd $(TT); make clean)

all: clean
	(cd $(TT); patch -p1 < ../$(TT).parachute.patch)
	@echo Building TTOOLS
	(cd $(TT); make)

install:
	(cd $(TT); sudo make install)
