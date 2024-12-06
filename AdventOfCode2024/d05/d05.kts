fun <T> List<T>.isSortedWith(comp: Comparator<T>): Boolean {
  return this.asSequence().zipWithNext().all{(a, b) -> comp.compare(a, b) <= 0}
}

fun solve(adjList: Map<Int, Set<Int>>, updates: List<List<Int>>, wantSorted: Boolean): Int {
  val comp: (Int, Int) -> Int = {a, b ->
    when {
      a == b -> 0
      (adjList[a]?.contains(b) ?: false) -> -1
      else -> 1
    }
  }
  return updates
    .filter{it.isSortedWith(comp) == wantSorted}
    .map{update -> update.sortedWith(comp)[update.size / 2]!!}
    .sum()
}

fun main(){
  val lines = generateSequence(::readlnOrNull).toList()
  val pairs: List<Pair<Int, Int>>  = lines.takeWhile{!it.isBlank()}.map{it.split("|").map(String::toInt)}.map{Pair(it[0], it[1])}
  val updates: List<List<Int>>  = lines.takeLastWhile{!it.isBlank()}.map{it.split(",").map(String::toInt)}

  val adjList: Map<Int, Set<Int>> = pairs.groupBy{(a, _) -> a}.mapValues{e -> e.value.map{(_, b) -> b}.toSet()}
  println("Part A: ${solve(adjList, updates, true)}")
  println("Part B: ${solve(adjList, updates, false)}")
}
main()
