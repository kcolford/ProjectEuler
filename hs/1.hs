module Main where

main = do
  print $ sum $ filter (\a -> a `mod` 3 == 0 || a `mod` 5 == 0) [1..999]
