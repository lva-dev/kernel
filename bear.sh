#!/usr/bin/env bash

mkdir -p build
make -nB | bear parse-sh -o build/compile_commands.json