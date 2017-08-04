d _ _ [] = 0
d t n (x:xs)
    | x + n >= t = 0
    | otherwise = 1+(d t (n+x) xs)

main = do
    [_, t] <- map read . words <$> getLine :: IO [Int]
    xs <- map read . words <$> getLine :: IO [Int]
    print $ d t 0 xs
