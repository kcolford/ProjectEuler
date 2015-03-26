module Main where

import Util

import Control.Monad
import Data.List

stuff = do x <- tails primes
           z <- inits x
           y <- takeWhile (< 1000000) $ scanl (+) 0 x
           guard $ isPrime y
           return y

main = print $ maximum stuff
