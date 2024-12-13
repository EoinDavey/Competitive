import kotlin.text.Regex
data class Vec(val x: Long, val y: Long)

val BIG: Long = 10000000000000

fun solve(a: Vec, b: Vec, prz: Vec): Long {
    val det = a.x * b.y - b.x * a.y
    if(det == 0L)
        return 0L
    val aprs_nn = prz.x * b.y - prz.y * b.x
    if(!(aprs_nn % det == 0L && aprs_nn / det >= 0L))
        return 0L
    val aprs = aprs_nn / det
    val bprs_nn = prz.y * a.x - prz.x * a.y
    if(!(bprs_nn % det == 0L && bprs_nn / det >= 0L))
        return 0L
    val bprs = bprs_nn / det
    return aprs * 3L + bprs
}

fun partA(inp: List<List<Vec>>) = inp.sumOf{(a, b, prz) -> solve(a, b, prz)}

fun partB(inp: List<List<Vec>>)
    = inp.sumOf{(a, b, prz) -> solve(a, b, Vec(prz.x + BIG, prz.y + BIG))}

fun main() {
    var ints = Regex("[0-9]+")
    val lines: List<List<Vec>> = generateSequence(::readlnOrNull)
        .chunked(4)
        .map{it.take(3)}
        .map{it.map{ints.findAll(it).map{it.value.toLong()}.toList()}}
        .map{it.map{ls -> Vec(ls[0]!!, ls[1]!!)}}
        .toList()
    println("Part A: ${partA(lines)}")
    println("Part B: ${partB(lines)}")
}
main()
