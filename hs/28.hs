module Main where

import Control.Monad
import Control.Monad.State

spiral v = [1] ++ fst (runState (filterM isCorner v) mods)
  where mods = [2,4..] >>= replicate 4

isCorner a = do
  (x:xs) <- get
  if 1 == a `mod` x
    then put xs >> return True
    else return False

main = do
  print $ sum $ spiral [2..1001 * 1001]
