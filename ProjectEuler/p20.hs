main = do
    let n = product [1..100]
    print $ sum $ map (\x -> (fromEnum x) - (fromEnum '0')) $ show n
