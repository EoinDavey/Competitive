import Control.Monad
main = do
    x <- readLn :: IO Int
    n <- readLn :: IO Int
    xs <- replicateM n readLn :: IO [Int]
    print $ x+ (sum $ map (x-) xs)
