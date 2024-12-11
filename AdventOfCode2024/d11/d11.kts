fun run(inp: List<Int>, steps: Int): Long {
    val memo = mutableMapOf<Pair<Long, Int>, Long>()
    fun f(v: Long, steps: Int): Long {
        if(steps == 0)
            return 1L
        if(v == 0L)
            return f(1, steps - 1)
        memo.get(Pair(v, steps))?.let{
            return it
        }
        val s = v.toString()
        val res = if(s.length % 2 == 0){
            f(s.take(s.length / 2).toLong(), steps - 1) +
                f(s.drop(s.length / 2).toLong(), steps - 1)
        } else {
            f(v * 2024L, steps - 1)
        }
        memo[Pair(v, steps)] = res
        return res
    }
    return inp.sumOf{f(it.toLong(), steps)}
}

fun partA(inp: List<Int>) = run(inp, 25)
fun partB(inp: List<Int>) = run(inp, 75)

fun main() {
    val l = readln().split(" ").map{it.toInt()}
    println("Part A: ${partA(l)}")
    println("Part B: ${partB(l)}")
}
main()
