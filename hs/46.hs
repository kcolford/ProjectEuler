module Main where

import Data.List
import Data.Maybe
import Util

oddComposite = filter (not . isPrime) [3,5..]

check n = any isPrime $ takeWhile (> 1) $ map foo [1..]
  where foo = (n -) . (* 2) . (^ 2)

main = print $ fromJust $ find (not . check) oddComposite
