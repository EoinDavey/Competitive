import kotlin.text.Regex
import kotlin.math.max
import kotlin.math.min

data class Vec(val x: Int, val y: Int) {
    override fun toString() = "($x,$y)"
}
data class Rect(val ul: Vec, val br: Vec)
data class Op(val inst: String, val rect: Rect)

fun overlap(a: Rect, b: Rect): Rect? {
    val ou = max(a.ul.x, b.ul.x)
    val ob = min(a.br.x, b.br.x)
    val ol = max(a.ul.y, b.ul.y)
    val or = min(a.br.y, b.br.y)
    if(ob >= ou && or >= ol)
        return Rect(Vec(ou, ol), Vec(ob, or))
    return null
}

fun Rect.area() = (br.x - ul.x + 1) * (br.y - ul.y + 1)

operator fun Rect.contains(o: Rect)
    = listOf(o.ul.x, o.br.x).all{it in ul.x..br.x} &&
        listOf(o.ul.y, o.br.y).all{it in ul.y..br.y}

fun Rect.remove(o: Rect): List<Rect> {
    val x_vals = listOf(
        Pair(ul.x, o.ul.x - 1),
        Pair(o.ul.x, o.br.x),
        Pair(o.br.x + 1, br.x),
    )
    val y_vals = listOf(
        Pair(ul.y, o.ul.y - 1),
        Pair(o.ul.y, o.br.y),
        Pair(o.br.y + 1, br.y),
    )
    val comps = x_vals.flatMap{(u, b) -> y_vals.map{(l, r) -> Rect(Vec(u,l), Vec(b,r))}}
        .filterIndexed{i, _ -> i != 4}
        .filter{it.area() > 0}
    if(comps.sumOf{it.area()} != area()-o.area()) {
        println("$this - $o = $comps")
    }
    return comps
}

fun blastRects(a: Rect, b: Rect): List<Rect> {
    val o = overlap(a, b)
    if(o == null)
        return listOf(a)
    return a.remove(o)
}

fun splitRects(rects: List<Rect>): List<Rect> {
    return rects.fold(listOf<Rect>()){ls, r ->
        val pruned = ls.flatMap{blastRects(it, r)}
        val os = ls.map{overlap(it, r)}.filterNotNull()
        val r_pruned = ls.fold(listOf(r)){acc, a ->
            acc.flatMap{blastRects(it, a)}
        }
        pruned + os + r_pruned
    }
}

fun partA(inp: List<Op>, split: List<Rect>): Int {
    val on = mutableSetOf<Rect>()
    for(op in inp) {
        val subs = split.filter{it in op.rect}
        when(op.inst){
            "turn on" -> on.addAll(subs)
            "turn off" -> on.removeAll(subs)
            "toggle" -> {
                for(s in subs) {
                    if(s in on)
                        on.remove(s)
                    else
                        on.add(s)
                }
            }
        }
    }
    return on.sumOf{it.area()}
}

fun partB(inp: List<Op>, split: List<Rect>): Int {
    val brtns = mutableMapOf<Rect, Int>()
    for(op in inp) {
        val subs = split.filter{it in op.rect}
        when(op.inst){
            "turn on" -> subs.forEach{brtns[it] = (brtns[it] ?: 0) + 1}
            "turn off" -> subs.forEach{brtns[it] = max(0, (brtns[it] ?: 0) - 1)}
            "toggle" -> subs.forEach{brtns[it] = (brtns[it] ?: 0) + 2}
        }
    }
    return brtns.map{(k, v) -> k.area() * v}.sum()
}

fun main(){
    val re = Regex("(turn on|turn off|toggle) ([0-9]+),([0-9]+) through ([0-9]+),([0-9]+)")
    val inp = generateSequence(::readlnOrNull)
        .map{re.matchEntire(it)!!.groupValues.drop(1)}
        .map{(a, b, c, d, e) -> Op(a, Rect(Vec(b.toInt(), c.toInt()), Vec(d.toInt(), e.toInt())))}
        .toList()
    val rects = inp.map{it.rect}
    val split = splitRects(rects)
    println("Part A: ${partA(inp, split)}")
    println("Part B: ${partB(inp, split)}")
}
main()
