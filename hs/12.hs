import Data.List
import Data.Maybe
import Util

factorLen = length . factor

main = do
  print $ fromJust $ find (\a -> factorLen a > 500) triNums
