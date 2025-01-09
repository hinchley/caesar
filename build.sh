#!/bin/sh
gcc -o caesar main.c

valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         ./caesar -e "My name is Pete"
