numbers = do
  x <- [100..999]
  y <- [x..999]
  let xy = x * y
      s = show xy
  if s /= reverse s 
    then fail ""
    else return $ x * y

main = do
  print $ foldl1 max numbers
