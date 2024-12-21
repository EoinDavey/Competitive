data class Vec(val x: Int, val y: Int) {
    operator fun plus(o: Vec): Vec = Vec(x + o.x, y + o.y)
}

enum class DirButton(val char: Char){
    UP('^'), DOWN('v'), LEFT('<'), RIGHT('>'), A('A')
}

fun DirButton.toMv() = when(this) {
    DirButton.UP -> Vec(-1, 0)
    DirButton.DOWN -> Vec(1, 0)
    DirButton.LEFT -> Vec(0, -1)
    DirButton.RIGHT -> Vec(0, 1)
    DirButton.A -> throw Error("A has no move")
}

interface State<K> {
    fun canPress(b: DirButton): Boolean
    fun press(b: DirButton): State<K>
}

data class DirPadState<K>(val pos: Vec, val child: State<K>) : State<DirPadState<K>> {
    override fun canPress(b: DirButton): Boolean {
        if(b == DirButton.A)
            return child.canPress(buttonHovered())
        val n = pos + b.toMv()
        return n.x in 0..1 && n.y in 0..2 && n != Vec(0, 0)
    }
    override fun press(b: DirButton): DirPadState<K> {
        if(b == DirButton.A)
            return DirPadState(pos, child.press(buttonHovered()))
        return DirPadState(pos + b.toMv(), child)
    }
    fun buttonHovered(): DirButton = when(pos) {
        Vec(0, 1) -> DirButton.UP
        Vec(0, 2) -> DirButton.A
        Vec(1, 0) -> DirButton.LEFT
        Vec(1, 1) -> DirButton.DOWN
        Vec(1, 2) -> DirButton.RIGHT
        else -> throw Error("Invalid position")
    }
}
data class NumPadState(val pos: Vec) : State<NumPadState> {
    override fun canPress(b: DirButton): Boolean {
        if(b == DirButton.A)
            return true
        val n = pos + b.toMv()
        return n.x in 0..3 && n.y in 0..2 && n != Vec(3, 0)
    }
    override fun press(b: DirButton): NumPadState {
        if(b == DirButton.A)
            return this
        return NumPadState(pos + b.toMv())
    }
}

fun numpadPos(c: Char) = when(c) {
    'A' -> Vec(3, 2)
    '0' -> Vec(3, 1)
    else -> (c.code - '0'.code - 1).let{Vec(2 - (it / 3), it % 3)}
}

typealias TotalState = DirPadState<DirPadState<NumPadState>>

fun distance(a: TotalState, b: TotalState): Int {
    val dist = mutableMapOf<TotalState, Int>(a to 0)
    val q = ArrayDeque<TotalState>(listOf(a))
    while(!q.isEmpty()){
        val st = q.removeFirst()
        val d = dist[st]!!
        if(st == b)
            return d
        for(v in DirButton.entries.filter{st.canPress(it)}.map{st.press(it)}) {
            if(v in dist)
                continue
            dist[v] = d + 1
            q.add(v)
        }
    }
    return 0
}

fun solve(tgt: String): Int {
    val start = DirPadState(Vec(0, 2), DirPadState(Vec(0, 2), NumPadState(Vec(3, 2))))
    var w = start
    var sm = 0
    for(c in tgt) {
        val dest = DirPadState(Vec(0, 2), DirPadState(Vec(0, 2), NumPadState(numpadPos(c))))
        sm += distance(w, dest) + 1
        w = dest
    }
    return sm
}

fun partA(tgts: List<String>): Int {
    val int = Regex("[0-9]+")
    return tgts.sumOf{solve(it) * int.find(it)!!.value.toInt()}
}

fun main(){
    val tgts = generateSequence(::readlnOrNull).toList()
    println("Part A: ${partA(tgts)}")
}
main()
