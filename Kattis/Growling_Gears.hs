import Control.Monad
import Data.List
main = do
    t <- readLn :: IO Int
    replicateM_ t (do
        n <- readLn :: IO Int
        xs <- replicateM n $ (do 
            map read . words <$> getLine)
        let (_,f) = maximum $ zip (map (\(a:b:c:rst) -> c + ((b**2.0) / (4 * a))) xs) [1..]
        print f)
