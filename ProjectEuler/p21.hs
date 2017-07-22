d x = sum $ map (\y -> if x `mod` y == 0 then y else 0) $ [1..(x-1)]

check x
    | x == d(c) && x/= c = x+c
    | otherwise = 0
    where c = d(x)

main = print $ ((`div` 2) . sum) $ map check [1..10000]
