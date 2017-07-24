import Control.Monad
import Data.List
import qualified Data.Map as Map
data Suit = Clubs | Spades | Hearts | Diamonds deriving (Show, Eq)

data Value = Bottom | Two | Three | Four | Five | Six | Seven | Eight | Nine | Ten | Jack | Queen | King | Ace
    deriving (Show, Eq, Ord, Enum)

valArr = [Two , Three , Four , Five , Six , Seven , Eight , Nine , Ten , Jack , Queen , King , Ace]

data Card = Card{ suit :: Suit
                , val ::  Value
                } deriving (Show, Eq)

strToCard :: String -> Card
strToCard (v:s:[]) = Card (suitMap Map.! s) (valMap Map.! v)

type Hand = [Card]

suitMap = Map.fromList [('C',Clubs),('S',Spades),('D',Diamonds),('H',Hearts)]
valMap = Map.fromList $ [('A',Ace),('2',Two),('3',Three),('4',Four),('5',Five),('6',Six)]
                        ++ [('7',Seven),('8',Eight),('9',Nine),('T',Ten), ('J',Jack)]
                        ++[('Q',Queen),('K',King)]

isFlush :: Hand -> Bool
isFlush h = and $ map (\c -> (suit c) == (suit (h!!0))) h

flush :: Hand -> Value
flush h = if isFlush h then highest h else Bottom

highest :: Hand -> Value
highest h = maximum $ map val h

count :: Hand -> Value -> Int
count h v = length $ filter ((==v) . val) h

hasN :: Hand -> Int -> Value
hasN h n = let v = filter ((==n) . count h) valArr in if length v == 0 then Bottom else maximum v

twoPair h = let v = filter((==2) . count h) valArr in if length v == 2 then hasN h 2 else Bottom

toStraightSeq xs
    | s == [2,3,4,5,14] = [1,2,3,4,5]
    | otherwise = s
    where s = sort xs

seqIncreasing [] _ = True
seqIncreasing [1,2,3,4,13] _ = True
seqIncreasing (x:xs) n = if x/=(n+1) then False else seqIncreasing xs x

isStraight h = if seqIncreasing l $ m - 1 then (toEnum m) else Bottom
    where l = toStraightSeq $ map (fromEnum . val) h
          m = (minimum l)

fullHouse h = let (th,tw) = ((hasN h 3), (hasN h 2)) in if th/=Bottom && tw/=Bottom
                                                        then (th,tw)
                                                        else (Bottom,Bottom)

straightFlush :: Hand -> Value
straightFlush h = if isFlush h
                  then isStraight h
                  else Bottom

compHand (h1,h2)
    | straightFlush h1 /= straightFlush h2 = straightFlush h1 > straightFlush h2
    | hasN h1 4 /= hasN h2 4 = hasN h1 4 > hasN h2 4
    | fullHouse h1 /= fullHouse h2 = fullHouse h1 > fullHouse h2
    | flush h1 /= flush h2 = flush h1 > flush h2
    | isStraight h1 /= isStraight h2 = isStraight h1 > isStraight h2
    | hasN h1 3 /= hasN h2 3 = hasN h1 3 > hasN h2 3
    | twoPair h1 /= twoPair h2 = twoPair h1 > twoPair h2
    | hasN h1 2 /= hasN h2 2 = hasN h1 2 > hasN h2 2
    | otherwise = highest h1 > highest h2

main = do
    let n = 5
    replicateM_ n (do
       l <- map strToCard . words <$> getLine :: IO [Card]
       let (p1,p2) = splitAt 5 l :: (Hand,Hand)
       print $ compHand (p1,p2))
