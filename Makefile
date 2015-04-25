all:
	@./compile-all.bash

clean:
	@./compile-all.bash --clean

.PHONY: clean all
