module Main where

import Data.List
import Data.Ord

cy 0 _ = repeat 0
cy a b = m:cy (m * 10) b
  where (d, m) = a `divMod` b
 
detect as = let (x:xs) = go as as in takeWhile (/= x) xs
  where go (x:xs) (_:y:ys) = if x == y then x:xs else go xs ys

check a = length $ detect $ cy 1 a

main = do 
  print $ maximumBy (comparing check) [1..1000]
