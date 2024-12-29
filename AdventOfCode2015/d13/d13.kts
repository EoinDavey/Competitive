data class InpEntry(val a: String, val b: String, val delta: Int)

fun key(a: String, b: String) = if(a < b) Pair(a, b) else Pair(b, a)

fun solve(names: List<String>, weights: Map<Pair<String, String>, Int>): Int {
    val n = names.size
    val memo = mutableMapOf<Triple<Int, Int, Int>, Int>()
    fun search(pos: Int, start: Int, state: Int): Int {
        if(state == (1 shl n) - 1)
            return weights[key(names[pos], names[start])] ?: 0
        val k = Triple(pos, start, state)
        memo[k]?.let{
            return it
        }
        return (0..<n)
            .filter{state.and(1 shl it) == 0}
            .maxOf{
                val w = weights[key(names[pos], names[it])] ?: 0
                w + search(it, start, state.or(1 shl it))
            }
            .also{
                memo[k] = it
            }
    }
    return (0..<n).maxOf{search(it, it, 1 shl it)}
}

fun partA(names: List<String>, weights: Map<Pair<String, String>, Int>)
    = solve(names, weights)

fun partB(names: List<String>, weights: Map<Pair<String, String>, Int>)
    = solve(names + "me", weights)

fun main(){
    val re = Regex("""([^\s]+).*(gain|lose) ([0-9]+).*to ([^\s]+).""")
    val lines = generateSequence(::readlnOrNull)
        .map{re.matchEntire(it)!!.groupValues.drop(1)}
        .map{(a, b, c, d) -> InpEntry(a, d, c.toInt() * (if(b == "lose") -1 else 1))}
        .toList()
    val weights = lines.groupingBy{key(it.a, it.b)}.fold(0){a, b -> a + b.delta}
    val names = lines.map{it.a}.distinct()
    println("Part A: ${partA(names, weights)}")
    println("Part B: ${partB(names, weights)}")
}
main()
