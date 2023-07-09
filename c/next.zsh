#!/bin/zsh

exercism download --exercise=$(head -1 problems.txt) --track=c

sed -i '' '1d' problems.txt
