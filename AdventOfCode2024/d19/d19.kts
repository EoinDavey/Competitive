fun count(pats: List<String>, tgt: String): Long {
  val dp = Array<Long>(tgt.length + 1){0}
  dp[tgt.length] = 1L
  for(i in tgt.length - 1 downTo 0) {
    dp[i] = pats
      .filter{i + it.length <= tgt.length}
      .filter{tgt.substring(i..<i+it.length) == it}
      .sumOf{dp[i + it.length]}
  }
  return dp[0]
}

fun partA(pats: List<String>, tgts: List<String>) = tgts.filter{count(pats, it) > 0}.count()
fun partB(pats: List<String>, tgts: List<String>) = tgts.sumOf{count(pats, it)}

fun main() {
  val lines = generateSequence(::readlnOrNull).toList()
  val pats = lines[0].split(", ")
  val tgts = lines.drop(2)
  println("Part A: ${partA(pats, tgts)}")
  println("Part B: ${partB(pats, tgts)}")
}
main()
