#!/bin/bash
#Filename: Desc Number conversion

echo "scale=2; 3/8" | bc

no=100
echo "obase=2; $no" | bc

no=1100100
echo "obase=10; ibase=2; $no" | bc

echo "sqrt(100)" | bc   # Square root
echo "10^10" | bc       # Square

