#!/bin/bash

CC="g++"

LIBS="-lgmp -lgmpxx -lm"

FLAGS="-g -O2 -std=c++11"

CCOPTS="-fstrict-aliasing -Wall -Wextra -Werror -Wchar-subscripts -Wundef -Wshadow -Wcast-align -Wwrite-strings -Wsign-compare -Wunused -Wno-unused-parameter -Wuninitialized -Winit-self -Wpointer-arith -Wredundant-decls -Wformat-nonliteral -Wno-format-zero-length -Wno-format-y2k -Wmissing-format-attribute -Wno-aggressive-loop-optimizations"

${CC} ${LIBS} ${FLAGS} ${CCOPTS} "$@" -o "${@%%.*}"
