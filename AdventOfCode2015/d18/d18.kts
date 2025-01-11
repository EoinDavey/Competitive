data class Vec(val x: Int, val y: Int)
operator fun Vec.plus(o: Vec) = Vec(x + o.x, y + o.y)
typealias Grid = List<List<Boolean>>
fun Grid.h() = this.size
fun Grid.w() = this[0].size
operator fun Grid.get(v: Vec) = this[v.x][v.y]
operator fun Grid.contains(v: Vec) = v.x in 0..<h() && v.y in 0..<w()

fun nbrs(v: Vec, g: Grid)
    = (-1..1).flatMap{dx -> (-1..1).map{dy -> Vec(dx, dy)}}.map{v + it}.filter{it in g && it != v}

fun isCorner(v: Vec, g: Grid)
    = (v.x == 0 || v.x == g.h() - 1) && (v.y == 0 || v.y == g.w() - 1)

fun next(g: Grid, cornersStuck: Boolean): Grid
    = (0..<g.h()).map{x ->
        (0..<g.w()).map{y ->
            val u = Vec(x, y)
            if(cornersStuck && isCorner(u, g))
                true
            else {
                val ns = nbrs(u, g).count{g[it]}
                (g[u] && ns in 2..3 || !g[u] && ns == 3)
            }
        }
    }

fun solve(g: Grid, cornersStuck: Boolean)
    = (1..100).fold(g){a, _ -> next(a, cornersStuck)}.sumOf{it.count{it}}

fun partA(g: Grid) = solve(g, false)
fun partB(g: Grid) = solve(g, true)

fun main(){
    val grid = generateSequence(::readlnOrNull)
        .map{it.map{it == '#'}}
        .toList()
    println("Part A: ${partA(grid)}")
    println("Part B: ${partB(grid)}")
}
main()
