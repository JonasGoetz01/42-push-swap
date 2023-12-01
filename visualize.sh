#!/bin/bash
make re
cd push_swap_visualizer
mkdir -p build
cd build
cmake ..
make
mv ./bin/visualizer ../../
cd ../../
./visualizer
