import Data.List
main = do
    g <- getLine
        putStrLn $ map (!! 0) $ group g
