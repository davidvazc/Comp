#!/bin/sh
flex $1
bison -y -d -t -v $2
cc -o $3 *.c
jucompiler.l
# 2 -> nome ficheiro y
jucompiler
