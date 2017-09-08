score xs ys = length $ filter (\(x,y) -> (x == y)) $ zip xs ys

main = do
    _ <- getLine
    s <- getLine
    let scores = map (\x -> score x s) [(cycle "ABC"),(cycle "BABC"), (cycle "CCAABB")]
    let results = zip ["Adrian","Bruno","Goran"] scores
    let mxS = maximum scores
    print mxS
    putStr $ unlines $ map (\(x,_) -> x) $ filter (\(_,y) -> y==mxS) results
