import java.util.PriorityQueue
import kotlin.math.min

data class Vec(val x: Int, val y: Int) {
    operator fun plus(o: Vec) = Vec(x + o.x, y + o.y)
    operator fun minus(o: Vec) = Vec(x - o.x, y - o.y)
}
val MVS = arrayOf(Vec(-1, 0), Vec(0, 1), Vec(1, 0), Vec(0, -1))

data class State(val pos: Vec, val dir: Int) {
    fun step() = State(pos + MVS[dir], dir)
    fun stepBack() = State(pos - MVS[dir], dir)
    fun cw() = State(pos, (dir + 1).mod(4))
    fun ccw() = State(pos, (dir - 1).mod(4))
}

typealias Grid = List<String>
fun Grid.h() = this.size
fun Grid.w() = this[0].length
operator fun Grid.contains(v: Vec) = v.x in 0..<h() && v.y in 0..<w()
operator fun Grid.get(v: Vec) = this[v.x][v.y]
fun Grid.find(c: Char): Vec?
    = (0..<h()).firstNotNullOfOrNull{x -> this[x].indexOf(c).takeIf{it != -1}?.let{Vec(x, it)}}

fun runDijk(grid: Grid, s : State): Map<State, Int> {
    data class DijkKey(val st: State, val dist: Int): Comparable<DijkKey> {
        override operator fun compareTo(other: DijkKey) = compareValues(dist, other.dist)
    }

    val dist = mutableMapOf<State, Int>(s to 0)
    val pq = PriorityQueue(listOf(DijkKey(s, 0)))
    while(!pq.isEmpty()) {
        val (u, d) = pq.poll()
        if(d > dist.get(u)!!)
            continue
        val stp = u.step()
        if(stp.pos in grid && grid[stp.pos] != '#' && dist.get(stp)?.takeIf{it <= d + 1} == null){
            dist[stp] = d + 1
            pq.add(DijkKey(stp, d + 1))
        }
        for(v in listOf(u.cw(), u.ccw())){
            if(dist.get(v)?.takeIf{it <= d + 1000} == null) {
                dist[v] = d + 1000
                pq.add(DijkKey(v, d + 1000))
            }
        }
    }
    return dist
}

fun partA(grid: Grid, s: Vec, e: Vec): Int {
    val dist = runDijk(grid, State(s, 1))
    return (0..3).map{dist[State(e, it)]}.filterNotNull().min()
}

fun partB(grid: Grid, s: Vec, e: Vec): Int? {
    val dist = runDijk(grid, State(s, 1))
    val bst = (0..3).map{dist[State(e, it)]}.filterNotNull().min()

    val starts = (0..3).map{State(e, it)}.filter{dist.get(it) == bst}
    val q = ArrayDeque<State>(starts)

    val seen = mutableSetOf<Vec>()
    while(!q.isEmpty()) {
        val u = q.removeFirst()
        val d = dist[u]!!

        seen.add(u.pos)

        val stpBack = u.stepBack()
        dist.get(stpBack)?.takeIf{it == d - 1}?.let{
            q.add(stpBack)
        }
        for(v in listOf(u.cw(), u.ccw())){
            dist.get(v)?.takeIf{it == d - 1000}?.let{
                q.add(v)
            }
        }
    }
    return seen.size
}

fun main() {
    val grid: Grid = generateSequence(::readlnOrNull).toList()
    val s = grid.find('S')!!
    val e = grid.find('E')!!

    println("Part A: ${partA(grid, s, e)}")
    println("Part B: ${partB(grid, s, e)}")
}
main()
