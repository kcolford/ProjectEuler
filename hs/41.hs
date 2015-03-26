module Main where

import Data.List
import Util

perm [] = return []
perm xs = do
  x <- xs
  y <- perm (filter (/= x) xs)
  return (x:y)

res = filter isPrime $ map read $ concatMap perm $ init $ tails "987654321"

main = print $ head res
