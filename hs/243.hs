module Main where

import Control.Monad
import Data.List
import Data.Ord
import Data.Ratio
import Util

resiliantRatioLessThan e = go 0 1 1 primes
  where
    go b a n xs'@(x:xs)
      | b /= 0 && b < n = fail "walked off the edge"
      | a' < e = return n
      | otherwise =
        case go b a'' n' xs of
          bs'@(b':_) -> bs' ++ go b' a'' n' xs'
          [] -> go b a'' n' xs'
      where a' = a * (if n /= 1 then n % (n - 1) else 1)
            a'' = a * (if n `mod` x == 0 then 1 else ((x - 1) % x))
            n' = n * x

solve e = minimum $ resiliantRatioLessThan e

main = do
  print $ solve (15499 % 94744)
  return ()
