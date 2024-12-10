typealias Pos = Pair<Int, Int>
typealias Grid = List<List<Int>>

operator fun Grid.contains(p: Pos): Boolean
  = p.first in 0..<this.size && p.second in 0..<this[0].size
operator fun<T> List<List<T>>.get(p: Pos): T = this[p.first][p.second]
operator fun Pos.plus(o: Pos) = Pos(this.first + o.first, this.second + o.second)

fun sumScores(grid: Grid, score: (Pos) -> Int): Int {
  val h = grid.size
  val w = grid[0].size
  return (0..<h).asSequence().flatMap{x -> (0..<w).asSequence().map{y -> Pos(x, y)}}
    .filter{grid[it] == 0}
    .sumOf(score)
}

fun nbrs(u: Pos, grid: Grid): List<Pos> {
  val MVS = arrayOf(Pos(0, 1), Pos(0, -1), Pos(1, 0), Pos(-1, 0))
  return MVS.map{d -> u + d}.filter{v -> v in grid}.filter{v -> grid[v] == grid[u] + 1}
}

fun partA(grid: Grid): Int {
  return sumScores(grid) {s ->
    val q = ArrayDeque<Pos>(listOf(s))
    val vis = mutableSetOf<Pos>(s)
    while(!q.isEmpty()) {
      val u = q.removeFirst()
      for(v in nbrs(u, grid)) {
        if(v in vis)
          continue
        vis.add(v)
        q.add(v)
      }
    }
    vis.asSequence().filter{grid[it] == 9}.count()
  }
}

fun partB(grid: Grid): Int {
  fun score(u: Pos, vis: MutableSet<Pos>): Int {
    if(grid[u] == 9)
      return 1
    var sm = 0
    for(v in nbrs(u, grid)){
      if(v in vis)
        continue
      vis.add(v)
      sm += score(v, vis)
      vis.remove(v)
    }
    return sm
  }
  return sumScores(grid) {score(it, mutableSetOf(it))}
}

fun main() {
  val grid = generateSequence(::readlnOrNull)
    .map{it.map{it.code - '0'.code}}
    .toList()
  println("Part A: ${partA(grid)}")
  println("Part B: ${partB(grid)}")
}
main()
