all: upload

build:
	pio run -e prod

compiledb:
	pio run -e prod -t compiledb

upload: build compiledb
	pio run -e prod -t upload

clean:
	pio run -e prod -t clean

.PHONY: all build compiledb upload clean
