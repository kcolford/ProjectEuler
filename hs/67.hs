simp (b:[])    = []
simp (a:b:abs) = max a b:simp (b:abs)

solve []     = repeat 0
solve (x:xs) = simp $ zipWith (+) x $ solve xs

main = do
  file <- readFile "67.in"
  let (a:as) = map (map read . words) $ lines file
  print $ head $ zipWith (+) a $ solve as
