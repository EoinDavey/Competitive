module Main where
import Control.Monad (forever, when)
import System.Exit (exitSuccess)

data BTree a = Tree {
    root  :: a,
    size :: Integer,
    left  :: BTree a,
    right :: BTree a
}
    | Empty
    deriving Show

fac x = product [1..x]

choose n k = (fac n) `div` (fac (n-k) * (fac k))

size' Empty = 0
size' t = size t

insert :: (Ord a) => BTree a -> a -> BTree a
insert Empty x = Tree x 1 Empty Empty
insert t x
    | x < (root t) = t{size=(size t) + 1, left= insert (left t) x}
    | otherwise    = t{size=(size t) + 1, right= insert (right t) x}

construct :: (Ord a) => [a] -> BTree a
construct xs = foldl insert Empty xs

nstrings :: BTree a -> Integer
nstrings Empty = 1
nstrings (Tree _ s l r) = ((s-1) `choose` n) * nstrings l * nstrings r
    where n = size' l
          m = size' r

main = forever $ do
    n <- read <$> getLine :: IO Int
    when (n==0) $ exitSuccess
    xs <- map read . words <$> getLine :: IO [Int]
    print . nstrings . construct $ xs
