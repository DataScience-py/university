#!/usr/bin/bash

for i in $(seq 1 10); do
	gcc "pw03-$i.c" -o "pw03-$i.out";
done
