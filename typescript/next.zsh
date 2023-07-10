#!/bin/zsh

problem=$(head -1 problems.txt)
exercism download --exercise=$problem --track=typescript

sed -i '' '1d' problems.txt

cd $problem

touch yarn.lock
yarn install
