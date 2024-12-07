fun canReach(tgt: Long, nums: List<Long>, withCat: Boolean = false): Boolean {
    fun f(idx: Int, res: Long): Boolean {
        if(res > tgt)
            return false
        if(idx == nums.size)
            return res == tgt
        return f(idx + 1, res * nums[idx])
            || f(idx + 1, res + nums[idx])
            || withCat && f(idx + 1, (res.toString() + nums[idx].toString()).toLong())
    }
    return f(1, nums[0])
}

fun partA(inp: List<Pair<Long, List<Long>>>): Long
    = inp.asSequence().filter{(tgt, nums) -> canReach(tgt, nums)}.map{it.first}.sum()

fun partB(inp: List<Pair<Long, List<Long>>>): Long
    = inp.asSequence().filter{(tgt, nums) -> canReach(tgt, nums, true)}.map{it.first}.sum()

fun main(){
    val inp: List<Pair<Long, List<Long>>> = generateSequence(::readlnOrNull)
        .map{it.split(": ")}
        .map{parts -> Pair(parts[0].toLong(), parts[1].split(" ").map(String::toLong))}
        .toList()
    println("Part A: ${partA(inp)}")
    println("Part B: ${partB(inp)}")
}
main()
