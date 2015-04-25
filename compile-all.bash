#!/bin/bash

msg() {
  echo "--> $@"
}

for f in ???
do
  EXEC="$f/PE-$f"

  if [[ "x$1" = "x--clean" ]];
  then
      [[ -e $EXEC ]] && msg "cleaning $EXEC..." && rm $EXEC
  else
      msg "compiling $EXEC..." && ./compile.bash "$EXEC.cpp"
  fi
done
