module Bob (responseFor) where

import regexpr;

responseFor :: String -> String
responseFor xs = xs =~ ".*?" 
