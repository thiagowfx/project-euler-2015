all:
	@./compile-all.bash

clean:
	@git clean -x -f -d

.PHONY: clean all
