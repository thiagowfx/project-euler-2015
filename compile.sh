#!/bin/bash

CC=g++

CCOPTS="-O2 -g -fstrict-aliasing -Wall -Wextra -Werror -Wchar-subscripts -Wundef -Wshadow -Wcast-align -Wwrite-strings -Wsign-compare -Wunused -Wno-unused-parameter -Wuninitialized -Winit-self -Wpointer-arith -Wredundant-decls -Wformat-nonliteral -Wno-format-zero-length -Wno-format-y2k -Wmissing-format-attribute"

RM="rm -f"

usage(){
    echo "Usage:"
    echo "  To compile all executables:"
    echo "    $0"
    echo "  To clean the project directory:"
    echo "    $0 clean"
}

clean(){
    # object files
    ${RM} **/*.o
    ${RM} **/*.pyc

    # executables
    find . -perm +100 -type f -name "PE-???" -or -name 'a.out' -delete
}

compile(){
    find . -type f -name "PE-???.cpp" -execdir ${CC} ${CCOPTS} {} \;
}

case "$@" in
    -h|--help)
        usage
        ;;
    clean)
        clean
        ;;
    *)
        compile
        ;;
esac
