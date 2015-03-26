module Main where

import Control.Monad
import Data.List
import Util

goodLen n = 9 >= length (getDigits n)

nums :: [Int]
nums = do x <- [0..100000]
          y <- takeWhile (\y -> goodLen [x,y,x*y]) [x..100000]
          guard $ isPandigital [x,y,x*y]
          return (x*y)

main = print $ sum $ nub nums
