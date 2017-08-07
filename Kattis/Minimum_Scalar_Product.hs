import Data.List
import Control.Monad
import Text.Printf
main = do
    t <- readLn :: IO Int
    ans <- replicateM t (do
        _ <- getLine
        xs <- map read . words <$> getLine :: IO [Int]
        ys <- map read . words <$> getLine :: IO [Int]
        return $ foldr (\(a,b) x -> x + a*b) 0 $ zip (sort xs) (reverse (sort ys)))
    let out = zip [1..(t+1)] ans
    mapM_ (\(i,a) -> printf "Case #%d: %d\n" i a) out
