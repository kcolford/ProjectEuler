import Data.List
import Data.Maybe
import Util

main = do
  print $ fromJust $ findIndex ((==) 1000 . length . show) fib
