#!/bin/bash

wartosci () {
 echo "Funkcja (pocz.): $*"
 set $(date "+%T")
 echo "Funkcja (date) : $*"
}

echo  "Glowny  (1)    : $*"
set $(date "+%T")
echo  "Glowny  (2)    : $*"
sleep 3
wartosci 11 22
echo  "Glowny  (3)    : $*"

exit 0
