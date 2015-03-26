module Main where

import Util

check a = go $ take (2 * l - 1) $ cycle s
  where s = show a
        l = length s
        go [] = return ()
        go (_:xs) = do
          let xs' = read $ take l xs
          if isPrime xs'
            then go xs
            else fail "Not valid."

search = do
  a <- takeWhile (< 1000000) primes
  check a
  return a

main = do
  print $ sum search
