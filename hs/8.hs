foo [] = []
foo (x:xs) = product (x:take 4 xs): foo xs

main = do 
  string <- readFile "8.in"
  print $ foldl1 max $ foo $ map (read . (:[])) string
