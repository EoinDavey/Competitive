import Control.Monad
import Control.Monad
main = do
    xs <- map read . words <$> getLine :: IO [Int]
    mapM_ (putStr . (++" ") . show) $ zipWith (-) [1,1,2,2,2,8] xs
