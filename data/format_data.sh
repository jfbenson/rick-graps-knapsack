#!/bin/bash

FILENAME="test.txt"

sed -i.bak -e "s/\s\s*(/\t(/" $FILENAME
sed -i -e "s/)\s\s*/)\t/" $FILENAME
sed -i -e "s/\s\s*[$]/\t$/" $FILENAME
sed -i -e "s/\s\s*\([0-9]*[%]\)/\t\1/g" $FILENAME
sed -i -e "s/\s\s*\([0-9]*\.[0-9]*\)/\t\1/g" $FILENAME
sed -i -e "s/\s\s*\(-\s\)/\t\1/g" $FILENAME
