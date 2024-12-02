import kotlin.math.abs

fun partA(ls1: List<Int>, ls2: List<Int>): Int = ls1.zip(ls2) { a, b -> abs(a - b) }.sum()
fun partB(ls1: List<Int>, ls2: List<Int>): Int {
    val counts = ls2.groupingBy{it}.eachCount();
    return ls1.map{x -> x * (counts.get(x) ?: 0)}.sum()
}

fun main() {
    val lines = generateSequence{ readlnOrNull() }.map{it.split("   ")}.toList()
    val ls1 = lines.map{it -> it[0].toInt()}.sorted()
    val ls2 = lines.map{it -> it[1].toInt()}.sorted()
    println(partA(ls1, ls2))
    println(partB(ls1, ls2))
}
