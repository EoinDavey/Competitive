import Data.Functor
import Control.Monad
md = 10^9 + 7
lm = 2^61

nxt (x,b) n
    | b || x > lm = Just $ (mod (ans - n) md,True)
    | n > ans = Nothing
    | otherwise = Just $ (ans - n,b)
    where ans = x*2

main = do
    _ <- readLn :: IO Int
    xs <- map read . words <$> getLine :: IO [Integer]
    let a = foldM nxt (1,False) xs
    putStrLn $ case a of Nothing -> "error"; Just x -> show $ fst x
