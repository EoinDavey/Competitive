main = do
    _ <- readLn :: IO Int
    xs <- map read . words <$> getLine :: IO [Int]
    print $ length $ filter (< 0) xs
