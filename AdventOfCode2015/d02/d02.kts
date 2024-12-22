import kotlin.math.min

fun paper(l: Int, w: Int, h: Int) = 2*l*w + 2*w*h + 2*h*l + min(l * w, min(w * h, h * l))

fun ribbon(l: Int, w: Int, h: Int)
    = min(2 * l + 2 * w, min(2 * l + 2 * h, 2 * w + 2 * h)) + l * w * h

fun partA(inps: List<List<Int>>) = inps.sumOf{(l, w, h) -> paper(l, w, h)}
fun partB(inps: List<List<Int>>) = inps.sumOf{(l, w, h) -> ribbon(l, w, h)}

fun main(){
    val int = Regex("[0-9]+")
    val inps = generateSequence(::readlnOrNull)
        .map{int.findAll(it).map{it.value.toInt()}.toList()}
        .toList()
    println("Part A: ${partA(inps)}")
    println("Part B: ${partB(inps)}")
}
main()
