#!/usr/bin/bash

for i in $(seq 1 9); do
	gcc "pw01-0$i.c" -o "pw01-0$i.out";
done
gcc pw01-10.c -o pw01-10.out

