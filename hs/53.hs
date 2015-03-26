import Util

main = do
  print $ length $ filter (> 1000000) $ do n <- [1..100]
                                           k <- [1..n]
                                           return $ n `choose` k
