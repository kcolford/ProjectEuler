{-# LANGUAGE NoMonomorphismRestriction #-}
{-# LANGUAGE CPP #-}
module Util where

import Control.Monad
import Control.Applicative
import Data.List (group, nub, sort)
import Control.Arrow

-- Generic Routines

fib = go 0 1
  where go a b = a:go b (a + b)

triNums = scanl1 (+) [1..]

factorial n = product [1..n]

mfilt :: Monad m => (a -> Bool) -> a -> m a
mfilt f a | f a       = return a
          | otherwise = fail "mfilt: condition failed"

integralSqrt n = mfilt (\x -> x * x == n) (f n)
    where f = truncate . sqrt . fromIntegral

mdivBy p n = liftM fst $ mfilt (\(_,m) -> m == 0) (n `divMod` p)

choose _ 0 = 1
choose 0 _ = 0
choose n k = choose (n-1) (k-1) * n `div` k

sortedElem _ []                 = False
sortedElem a (x:xs) | a > x     = False
                    | a == x    = True
                    | otherwise = a `sortedElem` xs

facSum a = (sum . init $ factor a) `asTypeOf` a

(|>) :: a -> (a -> b) -> b
(|>) a b = b a

class Digit n where
    getDigits :: n -> String

    isPandigitalOver :: String -> n -> Bool
    isPandigitalOver dgts n = let a = 9 == length (getDigits n)
                                  b = and $ map (`elem` getDigits n) dgts
                             in a && b

    isPandigital :: n -> Bool
    isPandigital = isPandigitalOver "123456789"
    
    toDigits :: n -> [Int]
    toDigits = map (\a -> fromEnum a - 48) . getDigits

instance Digit Int where getDigits = show

instance Digit Integer where getDigits = show

instance Digit a => Digit [a] where
    getDigits = concatMap getDigits

-- Prime Number Routines

primes = 2:_primes
    where _primes = 3:[x | x <- [5,7..], isPrimeBy x _primes]

isPrimeBy a xs = case wholeFactor a xs of
                   [] -> True
                   _  -> False

isPrime a = a > 1 && isPrimeBy a primes

-- Factorization Routines

wholeFactor _ [] = []
wholeFactor a (x:xs)  
    | d < x     = []
    | m == 0    = x:wholeFactor a xs
    | otherwise = wholeFactor a xs
    where (d, m) = a `quotRem` x

reduceFactor _ [] = []
reduceFactor a xs'@(x:xs)
    | a <= 1    = []
    | m == 0    = x:reduceFactor d xs'
    | otherwise = reduceFactor a xs
    where (d, m) = a `quotRem` x

#if 0
uniqueFactor _ [] = []
uniqueFactor a (x:xs)
    | a <= 1    = []
    | m == 0    = x:uniqueFactor rd xs
    | otherwise = uniqueFactor a xs
    where 
      (d,  m) = a `quotRem` x
      (rd, _) = let shrink = until (\(u,v) -> u > 1 && v == 0) 
                in shrink ((`quotRem` x) . fst) (a, 0)

primeFactorUnique a = uniqueFactor a primes

#else

primeFactorUnique = map head . group . primeFactor

#endif

completeFactorBy f xs a = if last l == head r 
                              then l ++ tail r
                              else l ++ r
  where l = a `f` xs
        r = reverse $ map (div a) l

factorBy = completeFactorBy wholeFactor

factorBy' = wholeFactor

factor = factorBy [1..]

primeFactor a = reduceFactor a primes


