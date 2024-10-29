#!/bin/bash

as -32 "$1" -o "$1".o
name=$(echo "$1" | cut -d "." -f 1)
ld -m elf_i386 "$1".o -o "$name".exe
rm "$1".o
