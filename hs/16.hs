import Util

main = do
  print $ sum $ toDigits (2 ^ 1000 :: Integer)
