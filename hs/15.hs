module Main where

import Data.Array

search (1, 1) = 1
search (a, b) = (if a > 1 then search' (a-1, b) else 0) +
                (if b > 1 then search' (a, b-1) else 0)

search' = (array bnds [(a, search a) | a <- range bnds] !)
  where bnds = ((1,1), (21,21))

main = do
  print $ search' (21, 21)
