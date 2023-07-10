#!/bin/zsh

problem=$(head -1 problems.txt)
exercism download --exercise=$problem --track=typescript

sed -i '' '1d' problems.txt

cd $problem

touch yarn.lock
yarn install

sed -i '' 's/xit/it/' $problem.test.ts

vim $problem.ts -c 'vsplit README.txt' -c "split $problem.test.ts" -c 'wincmd l' -c 'term yarn test --watch'
