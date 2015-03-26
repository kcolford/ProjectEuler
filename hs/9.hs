import Data.List
import Data.Maybe

pytrip = do
  m <- [1,2..]
  n <- [1,2..m]
  let a = m ^ 2 - n ^ 2
      b = 2 * m * n
      c = m ^ 2 + n ^ 2
  return (a, b, c)

main = do
  let (a, b, c) = fromJust (find (\(a, b, c) -> a + b + c == 1000) pytrip)
  print $ a * b * c
