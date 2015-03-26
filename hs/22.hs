import Data.List

alphaScore = sum . map f
  where f x = fromEnum x - off
        off = fromEnum 'A' - 1

main = do
  file <- readFile "22.in"
  let a = words $ map (\x -> if x `elem` "\"," then ' ' else x) file
      b = sum $ zipWith (*) [1..] $ map alphaScore $ sort a
  print b
