package main

import (
    "fmt"
)

func f(i int) int {
    i += 1
    for i%10 == 0 {
        i /= 10
    }
    return i
}

func main() {
    var N int
    fmt.Scan(&N)
    set := make(map[int]bool)
    cnt := 1
    set[N] = true
    for {
        N = f(N)
        if set[N] {
            break
        }
        set[N] = true
        cnt+=1
    }
    fmt.Println(cnt)
}
