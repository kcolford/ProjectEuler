module Main where

import Data.Map

year a = [31, if a `mod` 4 == 0 then 29 else 28, 31, 30, 31, 30, 31, 31, 
          30, 31, 30, 31]

cent = concatMap year [1901..2000]

checks = scanl (\a b -> (a + b) `mod` 7) 2 cent

test = Prelude.foldl (\a b -> insertWith (+) b 1 a) empty checks

main = do
  print $ test ! 0
