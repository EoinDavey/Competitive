import Control.Monad
import Data.List
import Data.Ord
import Data.Functor
toTup (a,b) = min (2*a) b

readInt :: (Num a, Read a) => IO [a]
readInt = map read . words <$> getLine

main = do
    [n,k] <- readInt :: IO [Int]
    xs <- replicateM n (readInt >>= \[a,b] -> return (a,b)) :: IO [(Integer,Integer)]
    let diff = sortBy (\a b -> compare (toTup b) (toTup a)) xs
    let new = (\(a,b) -> (map (\(l,r) ->(2*l,r)) a)++b) $ splitAt k diff
    print $ sum $ map (uncurry min) new
