main = do
  g <- getLine
  let z = zip g (cycle ['P','E','R'])
  print $ length $ filter (\(x,y) -> x/=y) z
