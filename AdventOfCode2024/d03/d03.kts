import kotlin.text.Regex

fun partA(input: String): Int {
  val reg = Regex("mul\\(([0-9]+),([0-9]+)\\)");
  return reg.findAll(input)
    .map{it.groupValues.drop(1).map{it.toInt()}.reduce(Int::times)}
    .sum()
}

fun partB(input: String): Int {
  val reg = Regex("mul\\(([0-9]+),([0-9]+)\\)|do\\(\\)|don't\\(\\)");
  return reg.findAll(input)
    .fold(Pair(0, true)) {(sm, enabled), match ->
      when(match.value){
        "do()" -> Pair(sm, true)
        "don't()" -> Pair(sm, false)
        else -> Pair(sm + if(enabled) match.groupValues.drop(1).map{it.toInt()}.reduce(Int::times) else 0, enabled)
      }
    }
    .first
}

fun main() {
  val input: String = generateSequence(::readlnOrNull).joinToString()
  println(partA(input))
  println(partB(input))
}

main()
