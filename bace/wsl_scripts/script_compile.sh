#!/bin/bash

cd /mnt/c/Users/wzygi/CLionProjects/bacaD

cp *.cpp *.hpp ~/baceP2
cd ~/baceP2

g++ -o plik main.cpp display.cpp garden.cpp fruit.cpp branch.cpp tree.cpp

echo "done!!!"
