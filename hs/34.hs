module Main where

import Data.Array

fac = (listArray (0,9) (scanl (*) 1 [1..9]) !)

limit = until (\x -> x * fac 9 < 10 ^ x) succ 1

check a = do
  let b = sum [fac (fromEnum x - 48) | x <- show a]
  if a == b
    then return a
    else fail "Not a valid number"

search = do
  a <- [3..10 ^ limit]
  check a
  return a

main = do
  print $ sum search
