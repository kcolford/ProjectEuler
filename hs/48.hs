main = print $ foldl f 0 [1..1000]
  where f a b = a `seq` (a + b ^ b) `mod` 10000000000
