import Util

amicable a = let b = facSum a
             in a /= b && a == facSum b

main = do
  print . sum $ filter amicable [2..10000]
