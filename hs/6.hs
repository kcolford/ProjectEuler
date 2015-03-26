main = do
  let a = sum [1..100] ^ 2
      b = sum $ map (^ 2) [1..100]
  print $ a - b
