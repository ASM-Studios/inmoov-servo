all: upload

build:
	pio run -e megaatmega2560

compiledb:
	pio run -e megaatmega2560 -t compiledb

upload: build compiledb
	pio run -e megaatmega2560 -t upload

clean:
	pio run -e megaatmega2560 -t clean

.PHONY: all build compiledb upload clean
