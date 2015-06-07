# Based on https://github.com/falconindy/cower/blob/master/Makefile
#          https://stackoverflow.com/questions/16751611/a-makefile-with-multiple-executables

SRCFILES   = $(wildcard **/*.cpp)
OBJFILES   = $(patsubst %.cpp, %.o, $(SRCFILES))
PROGFILES  = $(patsubst %.cpp, %, $(SRCFILES))

CPPFLAGS  := -std=c++11 -g -O2 -pedantic -fstrict-aliasing -Wall -Wextra -Werror -Wchar-subscripts -Wundef -Wshadow -Wcast-align -Wwrite-strings -Wsign-compare -Wunused -Wno-unused-parameter -Wuninitialized -Winit-self -Wpointer-arith -Wredundant-decls -Wformat-nonliteral -Wno-format-zero-length -Wno-format-y2k -Wmissing-format-attribute -Wno-aggressive-loop-optimizations $(CPPFLAGS)
LDLIBS     = -lgmp -lgmpxx -lm
LDFLAGS   := $(LDFLAGS)

all: $(PROGFILES)

clean:
	$(RM) $(PROGFILES) $(OBJFILES) *~

.PHONY: clean all