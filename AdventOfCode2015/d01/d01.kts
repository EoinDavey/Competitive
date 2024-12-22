fun partA(inp: String) = inp.map{if(it == '(') 1 else -1}.sum()
fun partB(inp: String)
    = inp.runningFold(0){acc, x -> acc + if(x == '(') 1 else -1}.indexOfFirst{it == -1}

fun main() {
    val inp = readln()
    println("Part A: ${partA(inp)}")
    println("Part B: ${partB(inp)}")
}
main()
