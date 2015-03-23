#!/bin/sh
[[ "x$1" = "x" ]] && echo "provide a number (e.g .007)" && exit 1
mkdir "$1" && cp 009/PE-009.cpp "$1"/PE-"$1".cpp
