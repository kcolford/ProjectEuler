main = do
  string <- readFile "13.in"
  let nums = map read $ lines string
  putStrLn $ take 10 $ show $ sum nums
