#!/bin/bash

# time= ./a.out 4 10
for i in {1..4}; do
echo `./a.out $i 10` >> times.csv
done