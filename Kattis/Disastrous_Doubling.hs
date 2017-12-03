import Data.Functor
import Control.Monad

md = 10^9 + 7
nxt x n = let ans = x*2 in if n > ans then Nothing else Just $ ans - n

main = do
    _ <- readLn :: IO Int
    xs <- map read . words <$> getLine :: IO [Integer]
    let a = foldM nxt 1 xs
    putStrLn $ case a of Nothing -> "error"; Just x -> show (rem x md)
