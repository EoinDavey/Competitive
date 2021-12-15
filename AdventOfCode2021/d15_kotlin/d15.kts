import java.util.PriorityQueue;

data class Point(val x: Int, val y: Int) {
    operator fun plus(p: Point): Point {
        return Point(this.x+p.x, this.y+p.y)
    }
}

data class DijkKey(val dist: Int, val pt: Point): Comparable<DijkKey> {
    override fun compareTo(other: DijkKey): Int {
        if(this.dist != other.dist)
            return this.dist.compareTo(other.dist)
        if(this.pt.x != other.pt.x)
            return this.pt.x.compareTo(other.pt.x)
        return this.pt.y.compareTo(other.pt.y)
    }
}

fun readInp(): List<List<Int>> {
    val seq = generateSequence{ readLine() }
        .map({str: String -> str.map({x: Char -> x.toInt() - '0'.toInt()})
                                .toList()})
        .toList()
    return seq;
}

val moves: Array<Point> = arrayOf(Point(0,1), Point(0,-1), Point(1,0), Point(-1,0))

val board = readInp()
val H = board.size
val W = board[0].size
val INF = 1000 * 1000 * 1000

fun valid(p: Point, h: Int, w: Int): Boolean {
    return 0 <= p.x && p.x < h && 0 <= p.y && p.y < w
}

fun ns(p: Point, h: Int, w: Int): List<Point> {
    return moves.map{x: Point -> x + p}
                .filter{x: Point -> valid(x, h, w)}
}

fun boardVal(p: Point): Int {
    val bidx: Int = p.x / H + p.y / W
    val bsx = p.x % H
    val bsy = p.y % W
    return (board[bsx][bsy] + bidx - 1) % 9 + 1
}

fun dijk(h: Int, w: Int): Int {
    val dist: HashMap<Point, Int> = HashMap()
    dist[Point(0,0)] = 0;
    val q: PriorityQueue<DijkKey> = PriorityQueue()
    q.add(DijkKey(0, Point(0,0)))
    while (!q.isEmpty()) {
        val (d, pt) = q.poll()!!
        if(dist.getOrElse(pt, { INF }) < d)
            continue
        for(n in ns(pt, h, w)){
            val nd = d + boardVal(n)
            if(dist.getOrElse(n, { INF }) > nd) {
                dist[n] = nd
                q.add(DijkKey(nd, n))
            }
        }
    }
    return dist[Point(h - 1, w - 1)] ?: 0
}

println("Part 1: ${dijk(H,W)}")
println("Part 2: ${dijk(5*H,5*W)}")
