#!/bin/bash

echo " " > fileInput.dat
for pl in $*
do
    grep 'GM (' ephemerides/$pl.txt | awk '{print $4}' >> fileInput.dat    
    grep -A3 SOE ephemerides/$pl.txt | tail -2 | sed 's/[XYZV=]/ /g' >> fileInput.dat
    echo " " >> fileInput.dat
done
