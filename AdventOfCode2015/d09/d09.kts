fun solve(n: Int, adjList: Map<Int, List<Pair<Int, Int>>>, comp: Comparator<Int>): Int? {
    val comp = nullsLast(comp)
    val memo = mutableMapOf<Pair<Int, Int>, Int?>()
    fun f(pos: Int, state: Int): Int? {
        if(state == (1 shl n) - 1)
            return 0
        val key = Pair(pos, state)
        memo[key]?.let{
            return it
        }
        return adjList[pos]
            ?.filter{(v, _) -> state.and(1 shl v) == 0}
            ?.minOfWith(comp){(v, w) -> f(v, state or (1 shl v))?.let{w + it}}
            .also{ memo[key] = it }
    }
    return (0..<n).minOfWith(comp){f(it, 1 shl it)}
}

fun partA(n: Int, adjList: Map<Int, List<Pair<Int, Int>>>) = solve(n, adjList, naturalOrder())
fun partB(n: Int, adjList: Map<Int, List<Pair<Int, Int>>>)
    = solve(n, adjList, naturalOrder<Int>().reversed())

fun main(){
    val lines = generateSequence(::readlnOrNull)
        .map{it.split(" ")}
        .map{Triple(it[0], it[2], it[4].toInt())}
        .toList()

    val keys = lines.flatMap{listOf(it.first, it.second)}.distinct()
    val idxMap = keys.mapIndexed{i, x -> Pair(x, i)}.toMap()
    val adjList = lines
        .flatMap{listOf(it, Triple(it.second, it.first, it.third))}
        .groupBy({idxMap[it.first]!!}, {Pair(idxMap[it.second]!!, it.third)})

    println("Part A: ${partA(keys.size, adjList)}")
    println("Part B: ${partB(keys.size, adjList)}")
}
main()
