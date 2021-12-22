package main

import (
    "bufio"
    "fmt"
    "os"
    "regexp"
    "sort"
    "strconv"
)

var (
    digRegexp = regexp.MustCompile(`-?[0-9]+`)
)

const (
    INF = 1000*1000*1000
)

type cube struct {
    vs [6]int
}

func newCube(x1, x2, y1, y2, z1, z2 int) *cube {
    return &cube {
        vs: [6]int{x1, x2, y1, y2, z1, z2},
    }
}

func (c* cube) axis(ax int) []int {
    // Awkward slice copying
    return append([]int(nil), c.vs[2 * ax:2 * ax + 2]...)
}

func (c *cube) hasInt(o *cube) bool {
    for ax := 0; ax < 3; ax++ {
        ax1, ax2 := c.axis(ax), o.axis(ax)
        if ax1[0] > ax2[1] || ax2[0] > ax1[1] {
            return false
        }
    }
    return true
}

func (c *cube) contains(o *cube) bool {
    for ax := 0; ax < 3; ax++ {
        ax1, ax2 := c.axis(ax), o.axis(ax)
        if ax2[0] < ax1[0] || ax2[1] > ax1[1] {
            return false
        }
    }
    return true
}

func (c *cube) volume() int64 {
    var prod int64 = 1
    for ax := 0; ax < 3; ax++ {
        axs := c.axis(ax);
        prod *= int64(axs[1]) - int64(axs[0]) + 1
    }
    return prod
}

func (c *cube) sub(o *cube) []*cube {
    is := [][][]int{}
    for ax := 0; ax < 3; ax++ {
        vs := append(c.axis(ax), o.axis(ax)...)
        sort.Ints(vs)
        axIvs := [][]int{}
        for i := 0; i < len(vs) - 1; i++ {
            a, b := vs[i], vs[i+1]
            if i == 0 {
                b--
            }
            if i == len(vs) - 2 {
                a++
            }
            if b < a {
                continue
            }
            axIvs = append(axIvs, []int{a,b})
        }
        is = append(is, axIvs)
    }

    cbs := []*cube{}
    for _, xiv := range is[0] {
        for _, yiv := range is[1] {
            for _, ziv := range is[2] {
                cb := newCube(xiv[0], xiv[1], yiv[0], yiv[1], ziv[0], ziv[1])
                cbs = append(cbs, cb)
            }
        }
    }
    out := []*cube{}
    for _, cb := range cbs {
        if !c.contains(cb) || o.contains(cb) {
            continue
        }
        out = append(out, cb)
    }
    return out
}

type pt struct {
    x, y, z int
}
type key = string
func (p pt) key() key {
    return fmt.Sprintf("%v-%v-%v", p.x, p.y, p.z)
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func runCom(com string, cb *cube, on []*cube) []*cube {
    for j := 0; j < len(on); j++ {
        c := on[j]
        if !cb.hasInt(c) {
            continue
        }
        //swap-delete
        on[len(on) - 1], on[j] = on[j], on[len(on) - 1]
        on = on[:len(on) - 1]
        on = append(on, c.sub(cb)...)
        j--
    }

    if com == "on" {
        on = append(on, cb)
    }
    return on
}
func onCbs(coms []string, cbs []*cube) []*cube {
    on := []*cube{}
    for i, cb := range cbs {
        on = runCom(coms[i], cb, on)
    }

    var sm int64 = 0
    for _, cb := range on {
        sm += cb.volume()
    }
    return on
}

func part1(on []*cube) {
    infL := newCube(51, INF, -INF, INF, -INF, INF)
    infR := newCube(-INF, -51, -INF, INF, -INF, INF)
    infU := newCube(-INF, INF, 51, INF, -INF, INF)
    infD := newCube(-INF, INF, -INF, -51, -INF, INF)
    infB := newCube(-INF, INF, -INF, INF, 51, INF)
    infF := newCube(-INF, INF, -INF, INF, -INF, -51)
    infs := []*cube{infU, infD, infL, infR, infB, infF}
    for _, inf := range infs {
        on = runCom("off", inf, on)
    }
    var sm int64 = 0
    for _, cb := range on {
        sm += cb.volume()
    }
    fmt.Printf("Part 1: %v\n", sm)
}

func part2(on []*cube) {
    var sm int64 = 0
    for _, cb := range on {
        sm += cb.volume()
    }
    fmt.Printf("Part 2: %v\n", sm)
}

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    cbs := []*cube{}
    coms := []string{}
    for scanner.Scan() {
        l := scanner.Text()
        vs := []int{}
        for _, num := range digRegexp.FindAllString(l, -1) {
            v, _ := strconv.Atoi(num)
            vs = append(vs, v)
        }
        cbs = append(cbs, newCube(vs[0], vs[1], vs[2], vs[3], vs[4], vs[5]))
        coms = append(coms, l[:2])
    }

    on := onCbs(coms, cbs)
    part2(on)
    part1(on)
}
