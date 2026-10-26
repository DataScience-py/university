#!/usr/bin/bash

for i in $(seq 1 5); do
	gcc "pw05-$i.c" -lm -o "pw05-$i.out";
done
