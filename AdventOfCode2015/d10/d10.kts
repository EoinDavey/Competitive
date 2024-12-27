fun seq(inp: List<Int>) = sequence {
    var w = inp
    while(true) {
        yield(w.size)
        val stck = mutableListOf<Pair<Int, Int>>()
        for((i, x) in w.withIndex()) {
            if(i > 0 && x == w[i - 1])
                stck[stck.size - 1] = stck.last().let{(a, b) -> Pair(a, b + 1)}
            else
                stck.add(Pair(x, 1))
        }
        w = stck.flatMap{(x, c) -> c.toString().map{it.code - '0'.code} + x}
    }
}

fun partA(inp: List<Int>) = seq(inp).elementAt(40)
fun partB(inp: List<Int>) = seq(inp).elementAt(50)

fun main(){
    val inp = readln().map{it.code - '0'.code}
    println("Part A: ${partA(inp)}")
    println("Part B: ${partB(inp)}")
}
main()
