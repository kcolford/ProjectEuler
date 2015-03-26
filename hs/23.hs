import Data.Array
import Util

isAbundant = (listArray (1, 28123) (map f [1..28123]) !)
  where f a = a < facSum a

abundant = filter isAbundant [1..]

valid = [x | x <- [1..28123], check x] 
  where 
    check a = all (f a) $ takeWhile (< a) abundant
    f a b = not $ isAbundant (a - b)

main = do
  print $ sum valid
