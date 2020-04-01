#!/bin/bash

gcc -I./includes -fPIC -c hfcal.c -o hfcal.o
# for macOS
gcc -shared hfcal.o -o ./libs/libhfcal.dylib

gcc -I./includes -c elliptical.c -o elliptical.o
gcc elliptical.o -L./libs -lhfcal -o elliptical
