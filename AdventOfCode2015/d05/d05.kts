fun isNiceA(inp: String)
    = inp.count{it in listOf('a','e','i','o','u')} >= 3 &&
        inp.zipWithNext().any{(a, b) -> a == b} &&
        listOf("ab", "cd", "pq", "xy").all{it !in inp}

fun isNiceB(inp: String)
    = inp.zipWithNext()
        .withIndex()
        .groupBy({(i, k) -> k}, {(i, k) -> i})
        .any{(_, v) -> v.last() > v.first() + 1} &&
      inp.zip(inp.drop(2)).any{(a, b) -> a == b}

fun partA(inps: List<String>) = inps.filter(::isNiceA).count()
fun partB(inps: List<String>) = inps.filter(::isNiceB).count()

fun main() {
    val inps = generateSequence(::readlnOrNull).toList()
    println("Part A: ${partA(inps)}")
    println("Part B: ${partB(inps)}")
}
main()
