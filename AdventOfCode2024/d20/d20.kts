import kotlin.math.max
import kotlin.math.min
import kotlin.math.abs

data class Vec(val x: Int, val y: Int) {
    operator fun plus(o: Vec) = Vec(x + o.x, y + o.y)
}
val MVS = arrayOf(Vec(0, 1), Vec(0, -1), Vec(-1, 0), Vec(1, 0))

typealias Grid = List<String>
fun Grid.h() = size
fun Grid.w() = this[0].length
fun Grid.find(c: Char)
    = (0..<h()).firstNotNullOfOrNull{x -> this[x].indexOf(c).takeIf{it != -1}?.let{Vec(x, it)}}
operator fun Grid.contains(v: Vec) = v.x in 0..<h() && v.y in 0..<w()
operator fun Grid.get(v: Vec) = this[v.x][v.y]

fun nbrs(u: Vec, grid: Grid) = MVS.map{u + it}.filter{it in grid}.filter{grid[it] != '#'}

fun runBFS(grid: Grid, s: Vec): Map<Vec, Int>{
    val dist = mutableMapOf<Vec, Int>(s to 0)
    val q = ArrayDeque<Vec>(listOf(s))
    while(!q.isEmpty()){
        val u = q.removeFirst()
        val d = dist[u]!!
        for(v in nbrs(u, grid).filter{it !in dist}){
            dist[v] = d + 1
            q.add(v)
        }
    }
    return dist
}

fun solve(grid: Grid, delta: Int): Int {
    val s = grid.find('S')!!
    val e = grid.find('E')!!
    val inf = grid.h() * grid.w() + 1

    val dist2s = runBFS(grid, s)
    val dist2e = runBFS(grid, e)
    val bst = dist2e[s]!!

    var cnt = 0
    for(ux in 0..<grid.h()){
        for(uy in 0..<grid.w()){
            if(grid[ux][uy] == '#')
                continue
            val u = Vec(ux, uy)
            for(vx in max(0, ux-delta)..min(ux+delta,grid.h()-1)){
                // |ux-vx| + |uy - vy| ≤ δ ⇒ |uy - vy| ≤ δ - |ux - vx|
                // ⇒  vy ≥ uy - δ +|ux-vx| ∧ vy ≤ uy + δ - |ux - vx|  
                for(vy in max(0, uy-delta + abs(ux-vx))..min(uy+delta-abs(ux-vx),grid.w()-1)){
                    if(grid[vx][vy] == '#')
                        continue
                    val v = Vec(vx, vy)
                    val cst = dist2s.getOrDefault(u, inf) +
                        abs(ux - vx) + abs(uy - vy) + dist2e.getOrDefault(v, inf)
                    if(bst - cst >= 100)
                        cnt++
                }
            }
        }
    }
    return cnt
}

fun main(){
    val grid = generateSequence(::readlnOrNull).toList()
    println("Part A: ${solve(grid, 2)}")
    println("Part B: ${solve(grid, 20)}")
}
main()
