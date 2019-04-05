#!/bin/bash

rm ./install.log 2>/dev/null 1>&2

if which gpio 2>/dev/null; then
  echo "Found wiring pi"
else
  echo "WiringPi not found. You should install it first"
  exit 1
fi

echo "Building node-wiring-pi ... "
node-gyp clean 2>&1 | tee -a ./install.log
node-gyp configure build 2>&1 | tee -a ./install.log
