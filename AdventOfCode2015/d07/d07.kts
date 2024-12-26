fun run(inp: Map<String, List<String>>, start: String): UShort {
    val int = Regex("[0-9]+")
    val memo = mutableMapOf<String, UShort>()
    fun f(s: String): UShort {
        if(int.matches(s))
            return s.toUShort()
        memo[s]?.let{
            return it
        }
        val ops = inp[s]!!
        val res = if(ops.size == 1)
                f(ops[0])
            else if(ops[0] == "NOT")
                f(ops[1]).inv()
            else ops.let{(a, b, c) -> when(b){
                    "AND" -> f(a) and f(c)
                    "OR" -> f(a) or f(c)
                    "LSHIFT" -> f(a).toInt().shl(f(c).toInt()).toUShort()
                    "RSHIFT" -> f(a).toInt().ushr(f(c).toInt()).toUShort()
                    else -> throw Error("Invalid")
                }
            }
        memo[s] = res
        return res
    }
    return f(start)
}

fun partA(inp: Map<String, List<String>>) = run(inp, "a")

fun partB(inp: Map<String, List<String>>)
    = run(inp + mapOf("b" to listOf(run(inp, "a").toString())), "a")

fun main(){
    val lines = generateSequence(::readlnOrNull)
        .map{it.split(" -> ")}
        .map{Pair(it[1], it[0].split(" "))}
        .toMap()
    println("Part A: ${partA(lines)}")
    println("Part B: ${partB(lines)}")
}
main()
