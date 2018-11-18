import Control.Monad
slve [a,b,c] = if mod c (gcd a b) == 0 then "Yes" else "No"
readInts :: String -> [Int]
readInts = map read . words
main = do
    t <- readLn :: IO Int
    forM_ [1..t] (\_ -> do
    	l <- fmap (slve. readInts) getLine
    	putStrLn l)
