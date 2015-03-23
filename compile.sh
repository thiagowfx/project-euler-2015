#!/bin/bash
#
# Copyright (C) 2015 Thiago Perrotta <perrotta dot thiago at poli dot ufrj dot br>
# Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#

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
