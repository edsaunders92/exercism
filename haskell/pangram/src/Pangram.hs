module Pangram (isPangram) where

import Data.Set (fromList, size)
import Data.Char (toLower, isAlpha, isAscii)

charCount:: String -> Int 
charCount text = size $ fromList $ map toLower $ filter isAlpha $ filter isAscii text

isPangram :: String -> Bool
isPangram text = charCount text == 26
