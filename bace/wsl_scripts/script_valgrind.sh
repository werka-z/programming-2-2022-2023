#!/bin/bash

cd /mnt/c/Users/wzygi/CLionProjects/bacaG

cp *.cpp *.h ~/baceP2
cd ~/baceP2

g++ -o plik main.cpp
valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./plik > output2.txt
# ./plik < testy.in > output2.txt

echo "done!!!"
