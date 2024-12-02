import kotlin.math.abs

fun safe(ls: List<Int>): Boolean {
    if ((1..(ls.size-2)).any{i ->
        ls[i] > ls[i-1] && ls[i] > ls[i + 1] || ls[i] < ls[i - 1] && ls[i] < ls[i + 1]
    }){
        return false
    }
    return ls.zipWithNext{a, b -> abs(a - b)}.all{it >= 1 && it <= 3}
}

fun partA(lines: List<List<Int>>): Int = lines.asSequence().filter{safe(it)}.count()

fun safeB(ls: List<Int>): Boolean {
    return (0..<ls.size).any{i -> safe(ls.slice(0..<i) + ls.slice(i+1..<ls.size))}
}

fun partB(lines: List<List<Int>>): Int = lines.asSequence().filter{safeB(it)}.count()

fun main() {
    val lines = generateSequence{readlnOrNull()}
        .map{it.split(" ").map{it.toInt()}.toList()}
        .toList()
    println(partA(lines))
    println(partB(lines))
}
