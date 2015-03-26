module Main where

ones = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
together a b = if a /= "" && b /= "" then a ++ "and" ++ b else a ++ b
stuff = do
  first <- ones
  let first' = if first /= "" then first ++ "hundred" else first
  second <- ones
  if second == "one"
    then do third <- ones
            let third' = case third of
                  "" -> "ten"
                  "one" -> "eleven"
                  "two" -> "twelve"
                  "three" -> "thirteen"
                  "five" -> "fifteen"
                  "eight" -> "eighteen"
                  _ -> third ++ "teen"
            return $ together first' third'
    else do let second' = case second of
                  "" -> ""
                  "two" -> "twenty"
                  "three" -> "thirty"
                  "four" -> "forty"
                  "five" -> "fifty"
                  "eight" -> "eighty"
                  _ -> second ++ "ty"
            third <- ones
            return $ together first' (second' ++ third)

main = do
  print $ length $ concat (stuff ++ ["onethousand"])
