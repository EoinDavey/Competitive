fun run(inits: List<Long>, prog: List<Int>): Sequence<Int> {
  return sequence{
    val regs = inits.toMutableList()
    var ip = 0
    fun combo(op: Int): Long = when(op) {
      in 0..3 -> op.toLong()
      in 4..6 -> regs[op - 4]
      else -> throw Error("7 not valid")
    }

    while(ip + 1 < prog.size) {
      val opc = prog[ip++]
      val opr = prog[ip++]
      when(opc) {
        0 -> regs[0] = (regs[0] shr combo(opr).toInt())
        1 -> regs[1] = regs[1] xor opr.toLong()
        2 -> regs[1] = combo(opr).mod(8L)
        3 -> if(regs[0] != 0L) ip = opr
        4 -> regs[1] = regs[1] xor regs[2]
        5 -> yield(combo(opr).mod(8))
        6 -> regs[1] = (regs[0] shr combo(opr).toInt())
        7 -> regs[2] = (regs[0] shr combo(opr).toInt())
        else -> throw Error("Invalid op code")
      }
    }
  }
}

fun partA(inits: List<Long>, prog: List<Int>)
  = run(inits, prog).map{it.toString()}.joinToString(",")

fun partB(inits: List<Long>, prog: List<Int>)
  = prog.foldRight(listOf(0L)) {p, prevs ->
      prevs.flatMap{prev ->
        (0..7).map{(prev shl 3) + it}
          .filter{run(listOf(it) + inits.drop(1), prog).first() == p}
      }
    }.min()

fun main() {
  val inits = buildList{
    repeat(3){
      add(readln().split(": ")[1].toLong())
    }
  }
  readln()
  val prog = readln().split(": ")[1].split(",").map{it.toInt()}
  println("Part A: ${partA(inits, prog)}")
  println("Part B: ${partB(inits, prog)}")
}
main()
