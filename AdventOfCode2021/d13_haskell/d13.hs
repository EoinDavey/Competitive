import Control.Monad (join)
import Data.Bifunctor (bimap)
import Data.Set (Set, empty, fromList, size, member)
import qualified Data.Set as Set (map)

splitLs :: (Eq a) => [a] -> a -> ([a], [a])
splitLs ls elt = (\(a,b) -> (a, tail b)) $ span (/= elt) ls

readDots :: String -> (Int, Int)
readDots str = join bimap read $ splitLs str ','

readFolds :: String -> (String, Int)
readFolds s = bimap (drop (length "fold along ")) read $ splitLs s '='

type Input = ([(Int, Int)], [(String, Int)])
procInp :: String -> Input
procInp x = bimap (map readDots) (map readFolds) $ splitLs (lines x) ""

doFold brd v idx = (flip Set.map) brd
                   (\(x,y) -> if idx == 0
                              then if x < v then (x,y) else (2 * v - x, y)
                              else if y < v then (x,y) else (x, 2 * v - y))

fold brd axis v = if axis == "x" then doFold brd v 0 else doFold brd v 1

minMaxRange ls = [(minimum ls)..(maximum ls)]

printGrid brd = unlines [[if member (x,y) brd then '#' else ' ' | x <- xs ] | y <- ys]
    where xs = minMaxRange $ Set.map (\(x,_) -> x) brd
          ys = minMaxRange $ Set.map (\(_,y) -> y) brd

partA (dots, folds) = size $ uncurry (fold (fromList dots)) $ head folds

partB (dots, folds) = printGrid $ foldl (\brd f -> uncurry (fold brd) $ f) (fromList dots) folds

runProg s = unlines ["Part 1: " ++ (show $ partA inp), "Part 2:"] ++ (partB inp)
    where inp = procInp s

main = interact runProg
