#!/bin/sh

if [ $# -gt 0 ]; then
  gdb --command=Command.txt --args test "$*"
else
  gdb --command=Command.txt test
fi

