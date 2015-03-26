module Main where

deleter []     = return []
deleter (x:xs) = xs:map (x:) (deleter xs)

perms [] = return []
perms bs = do
  (x, xs) <- zip bs (deleter bs)
  p <- perms xs
  return $ x:p

main = do
  putStrLn $ concatMap show $ perms [0..9] !! 999999
