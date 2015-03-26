{-# LANGUAGE NoMonomorphismRestriction #-}
module Main where

import Util
import Data.Array.Unboxed
import Data.List
import Control.Arrow
import Data.Ord
import Data.Function

tableGen t []     = t
tableGen t (p:ps) = tableGen t' ps
    where
      (s, e) = bounds t
      r = let n x = x + (p - (x `mod` p))
          in enumFromThenTo (n s) (n (s + p)) e
      t' = accum (+) t (zip r (repeat 1))

table :: Int -> UArray Int Int
table st = let b = (st, st + 10000)
           in tableGen (array b $ zip (range b) (repeat 0)) $ take 5000 primes

scanTable = map fst . filter ((== 4) . snd) . assocs . table

deltas = map (uncurry (-) &&& id) . uncurry zip . (tail &&& id) . scanTable

segment [] = []
segment xs = let (x, xs') = splitAt 10000 xs
             in x:segment xs'

searchDeltas = let group = map unzip . groupBy ((==) `on` fst)
               in lookup [1,1] . group . deltas

searchAllDeltas = map searchDeltas [1,9995..500000]

search n xxs@(x:xs) | all (== n) lls = x:search n xs
                    | otherwise      = search n xs
    where nns = take n xxs
          pps@(p:ps) = map primeFactorUnique nns
          lls = map length pps

main = print $ take 20 $ search 2 [3..]
