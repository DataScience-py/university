#!/usr/bin/bash

for i in $(seq 1 5); do
	gcc "pw04-$i.c" -o "pw04-$i.out";
done
