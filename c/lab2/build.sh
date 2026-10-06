#!/usr/bin/bash

for i in $(seq 1 9); do
	gcc "pw02-0$i.c" -o "pw02-0$i.out";
done
gcc pw02-10.c -o pw02-10.out

