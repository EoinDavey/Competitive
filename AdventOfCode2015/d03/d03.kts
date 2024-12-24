data class Vec(val x: Int, val y: Int) {
    operator fun plus(o: Vec) = Vec(x + o.x, y + o.y)
}
fun charToVec(c: Char) = when(c) {
    '^' -> Vec(-1, 0)
    'v' -> Vec(1, 0)
    '<' -> Vec(0, -1)
    else -> Vec(0, 1)
}
fun visits(inp: String) = inp.runningFold(Vec(0, 0)){acc, c -> acc + charToVec(c)}

fun partA(inp: String) = visits(inp).distinct().count()
fun partB(inp: String) = (visits(inp.filterIndexed{i, _ -> i % 2 == 0}) +
    visits(inp.filterIndexed{i, _ -> i % 2 != 0})).distinct().count()

fun main(){
    val inp = readln()
    println("Part A: ${partA(inp)}")
    println("Part B: ${partB(inp)}")
}
main()
