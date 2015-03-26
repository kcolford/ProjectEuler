import Util

main = do
  print $ sum $ toDigits $ (product [1..100] :: Integer)
