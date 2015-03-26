import Util
import Data.List
import Control.Monad
import qualified Data.Set as S

generate q []     = return $ read $ reverse q
generate q (p:ps) = do t <- tval p \\ q
                       gen p (t:q) ps
    where
      tval 2 = "02468"
      tval 5 = "05"
      tval _ = "0123456789"

      gen 1 = generate
      gen 2 = generate
      gen 5 = generate
      gen p = \q@(t:s:f:_) -> if read (f:s:t:[]) `rem` p == 0 
                              then generate q
                              else const []

vals :: [Integer]
vals = generate [] $ replicate 3 1 ++ take 7 primes

main = print $ sum vals
