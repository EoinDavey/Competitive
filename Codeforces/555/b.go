package main

import (
    "fmt"
    "strings"
    "strconv"
)

var f [10]int

func main() {
    var N int
    fmt.Scan(&N)
    var in string
    fmt.Scan(&in)
    a := make([]int, N)

    for i, c := range strings.Split(in, "") {
        a[i], _ = strconv.Atoi(c)
    }

    for i := 1; i <= 9; i++ {
        fmt.Scan(&f[i])
    }

    for i := 0; i < N; i++ {
        if f[a[i]] <= a[i] {
            continue
        }
        for i < N && f[a[i]] >= a[i] {
            a[i] = f[a[i]]
            i++
        }
        break
    }
    for _, x := range a{
        fmt.Print(x)
    }
    fmt.Println()
}
