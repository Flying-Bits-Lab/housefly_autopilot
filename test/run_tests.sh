#!/bin/bash
gcc ../src/*.c test.c unity.c -o test
./test && rm -rf test
