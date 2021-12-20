import std/strutils
import std/tables
import std/sets
import std/sequtils

type Point = tuple[x: int, y: int]
let mvs = [(1, 1), (1, 0), (1, -1), (0, 1), (0, 0), (0, -1), (-1, 1), (-1, 0), (-1, -1)]

proc ns(pt: Point): seq[Point] =
    var o: seq[Point] = @[]
    for mv in mvs:
        o.add((pt.x+mv[0], pt.y+mv[1]))
    return o

let lines = splitLines(readAll(stdin))

let alg = lines[0]

let ob = newTable[Point, char]()

for x, line in lines[2 .. ^1]:
    for y, c in line:
        ob[(x, y)] = c

proc pts2Update(tbl: TableRef[Point, char]): seq[Point] =
    var s: HashSet[Point] = initHashSet[Point]()
    for k in tbl.keys:
        for n in ns(k):
            s.incl(n)
    return toSeq(s)

proc sim(its: int): int =
    var b = ob
    var rest: char = '.'
    for i in 1 .. its:
        var nb = newTable[Point, char]()
        for pt in pts2Update(b):
            var sm = 0
            for off, n in ns(pt):
                if b.getOrDefault(n, rest) == '.':
                    continue
                sm += 1 shl off
            nb[pt] = alg[sm]
        if rest == '.':
            rest = alg[0]
        else:
            rest = alg[^1]
        b = nb
    var cnt = 0
    for v in b.values:
        if v == '#':
            cnt += 1
    return cnt
    
echo "Part 1: ", sim(2)
echo "Part 2: ", sim(50)
