#!/bin/bash

msg() {
  echo "--> $@"
}

for f in ???
do
  msg "compiling $f..."
  ./compile.bash $f/PE-$f.cpp
done
