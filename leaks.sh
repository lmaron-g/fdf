#!/bin/bash

make
./fdf maps/pyramide.fdf &
sleep 1
PID="$(ps | grep fdf | head -n1 | awk '{print $1}')"
leaks $PID