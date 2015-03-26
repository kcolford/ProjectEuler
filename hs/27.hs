module Main where

import Util

eval a b = map (\n -> n * n + a * n + b) [0..]

possible = do
  b <- takeWhile (< 1000) primes
  a <- [-b..b]
  let test = takeWhile isPrime $ eval a b
      count = length test
  return (count, a * b)

main = do
  print $ snd $ maximum possible
