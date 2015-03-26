module Main where

check a = sum [(fromEnum x - 48) ^ 5 | x <- show a]

main = do
  print $ sum [x | x <- [2..999999], x == check x]
