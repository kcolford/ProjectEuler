module Main where

import Data.Set

main = do
  print $ size $ fromList [a ^ b | a <- [2..100], b <- [2..100]]
