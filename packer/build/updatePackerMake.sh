#!/bin/bash
cd ./binPacker/
rm *
cp ../qtGen/Packer.pro ./
qmake Packer.pro
cd ..
