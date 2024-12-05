fun solve(adjList: Map<Int, Set<Int>>, updates: List<List<Int>>, wantSorted: Boolean): Int {
  class Data(val x: Int) : Comparable<Data> {
    override operator fun compareTo(other: Data): Int {
      return when {
        this.x == other.x -> 0
        (adjList[this.x]?.contains(other.x) ?: false) -> -1
        else -> 1
      }
    }
  }
  return updates.map{update ->
    val sorted = update.sortedBy{x -> Data(x)}
    if((update == sorted) == wantSorted) {
      sorted[update.size / 2]!!
    } else {
      0
    }
  }.sum()
}

fun partA(adjList: Map<Int, Set<Int>>, updates: List<List<Int>>): Int = solve(adjList, updates, true)
fun partB(adjList: Map<Int, Set<Int>>, updates: List<List<Int>>): Int = solve(adjList, updates, false)

fun main(){
  val lines = generateSequence(::readlnOrNull).toList()
  val pairs: List<Pair<Int, Int>>  = lines.takeWhile{!it.isBlank()}.map{it.split("|").map{it.toInt()}}.map{Pair(it[0], it[1])}
  val updates: List<List<Int>>  = lines.takeLastWhile{!it.isBlank()}.map{it.split(",").map{it.toInt()}}

  val adjList = mutableMapOf<Int, MutableSet<Int>>()
  for((a, b) in pairs) {
    adjList.getOrPut(a, ::mutableSetOf).add(b)
  }
  println(partA(adjList, updates))
  println(partB(adjList, updates))
}
main()
