#!/bin/zsh

exercism download --exercise=$(head -1 problems.txt) --track=typescript

sed -i '' '1d' problems.txt
