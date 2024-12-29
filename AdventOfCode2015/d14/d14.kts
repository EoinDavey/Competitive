import kotlin.math.min

val TIME_LIM = 2503

data class InpEntry(val name: String, val speed: Int, val flyTime: Int, val restTime: Int)

fun InpEntry.distAfter(t: Int)
    = speed * (flyTime * (t / (flyTime + restTime)) + min(t % (flyTime + restTime), flyTime))

fun partA(inps: List<InpEntry>) = inps.maxOf{it.distAfter(TIME_LIM)}

fun partB(inps: List<InpEntry>): Int {
    val n = inps.size
    val scores = IntArray(n)
    for(t in 1..TIME_LIM){
        val ds = inps.map{it.distAfter(t)}
        val bst = ds.max()
        for(i in 0..<n)
            if(ds[i] == bst)
                scores[i]++
    }
    return scores.max()
}

fun main(){
    val re = Regex("""([^\s]+).+?([0-9]+).+?([0-9]+).+?([0-9]+).*""")
    val lines = generateSequence(::readlnOrNull)
        .map{re.matchEntire(it)!!.groupValues.drop(1)}
        .map{(a, b, c, d) -> InpEntry(a, b.toInt(), c.toInt(), d.toInt())}
        .toList()
    println("Part A: ${partA(lines)}")
    println("Part B: ${partB(lines)}")
}
main()
