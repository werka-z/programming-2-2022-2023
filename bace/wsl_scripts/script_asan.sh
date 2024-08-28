#!/bin/bash

cd /mnt/c/Users/wzygi/CLionProjects/bacaG

cp *.cpp *.h ~/baceP2
cd ~/baceP2
g++ -g -Wall -Wextra -Wshadow -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -o plik main.cpp
#g++ -g -Wall -Wextra -Wshadow -o plik main.cpp 
#./plik < testy.in > output2.txt
#./plik > output.txt
echo "done!!!"
