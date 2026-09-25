#!/usr/bin/env bash
set -e
echo "Creating ./bin directory..."
mkdir -p ./bin

make

echo "Running RecompModTool..."
./RecompModTool ./mod.toml ./bin

echo "Zipping output file into ./bin..."
zip -j ./bin/slow_dk_phase.zip ./bin/slow_dk_phase.nrm

echo "Complete"