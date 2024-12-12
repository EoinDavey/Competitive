val MVS = arrayOf(Pos(0, 1), Pos(0, -1), Pos(1, 0), Pos(-1, 0))
typealias Grid = List<String>
data class Edge(val pos: Pos, val dir: Pos)
data class Pos(val x: Int, val y: Int) {
  operator fun plus(o: Pos): Pos = Pos(x + o.x, y + o.y)
}
operator fun Grid.contains(pos: Pos): Boolean
  = pos.x in 0..<this.size && pos.y in 0..<this[0].length
operator fun Grid.get(pos: Pos): Char = this[pos.x][pos.y]!!

fun nbrs(u: Pos, grid: Grid): List<Pos> = MVS.map{u + it}.filter{it in grid}

fun getEdges(u: Pos, grid: Grid): List<Edge>
  = MVS.filter{u + it !in grid || grid[u + it] != grid[u]}.map{Edge(u, it)}

fun colour(grid: Grid): Map<Int, List<Pos>> {
  val h = grid.size
  val w = grid[0].length

  val cols = mutableMapOf<Pos, Int>()
  fun flood(u: Pos, col: Int) {
    cols[u] = col
    for(v in nbrs(u, grid)) {
      if(grid[v] == grid[u] && v !in cols){
        flood(v, col)
      }
    }
  }
  var nextCol = 1
  for(x in 0..<h) {
    for(y in 0..<w) {
      val p = Pos(x, y)
      if(p in cols)
        continue
      flood(p, nextCol)
      nextCol += 1
    }
  }
  return cols.asIterable().groupBy({(u, c) -> c}, {(u, c) -> u})
}


fun countEdges(shape: List<Pos>, grid: Grid): Int {
  val ufdsMap = mutableMapOf<Edge, Edge?>()
    .apply{shape.forEach{getEdges(it, grid).associateWithTo(this, {null})}}
  fun getP(e: Edge): Edge {
    ufdsMap[e]?.let{
      val p = getP(it)
      ufdsMap[e] = p
      return p
    }
    return e
  }
  fun union(e: Edge, f: Edge) {
    val pe = getP(e)
    val pf = getP(f)
    if(pe != pf)
      ufdsMap[pe] = pf
  }
  shape.forEach{u ->
    nbrs(u, grid).forEach{v ->
      MVS.forEach{d ->
        val e1 = Edge(u, d)
        val e2 = Edge(v, d)
        if(e1 in ufdsMap && e2 in ufdsMap)
          union(e1, e2)
      }
    }
  }
  return ufdsMap.asSequence().filter{(_, p) -> p == null}.count()
}

fun partA(grid: Grid): Int
  = colour(grid).asIterable().sumOf{(_, ls) -> ls.size * ls.sumOf{getEdges(it, grid).size}}

fun partB(grid: Grid): Int
  = colour(grid).asIterable().sumOf{(_, ls) -> ls.size * countEdges(ls, grid)}

fun main() {
  val lines: Grid = generateSequence(::readlnOrNull).toList()
  println("Part A: ${partA(lines)}")
  println("Part B: ${partB(lines)}")
}
main()
