import Data.Array
import Data.List
import Data.Ord

chain a 
  | a == 1 = 1
  | even a = a `div` 2
  | otherwise = 3 * a + 1

get 1 = 0
get x = 1 + get' (chain x)

get' a = if a < 1000000 then mapping ! a else get a
  where mapping = listArray (1, 1000000) $ map get [1..1000000]

main = do
  print $ maximumBy (comparing get') [1..1000000]
