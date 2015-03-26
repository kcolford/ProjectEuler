module Main where

search 0 _      = 1
search _ []     = 0
search d (x:xs) = sum [search d' xs | d' <- takeWhile (>= 0) [d,d - x..]]

main = do
  print $ search 200 [200,100,50,20,10,5,2,1]
