DASM = dasm

clean:
	rm -rf $(DASM)

all: clean
	mkdir -p $(DASM)
	@echo Extracting original dasm archive and patching
	(cd $(DASM); unzip ../dasm.zip)
	(cd $(DASM); patch -p1 < ../dasm.parachute.patch)
	@echo Building dasm
	(cd $(DASM); make)

install:
	(cd $(DASM); sudo make install)
