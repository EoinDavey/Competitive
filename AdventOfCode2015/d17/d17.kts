import kotlin.math.min

val TGT = 150

fun partA(nums: List<Int>): Int {
    val n = nums.size
    val memo = mutableMapOf<Pair<Int, Int>, Int>()
    fun f(p: Int, rem: Int): Int {
        if(p == n)
            return if(rem == 0) 1 else 0
        val key = Pair(p, rem)
        memo[key]?.let{
            return it
        }
        val ans = f(p + 1, rem) + (if(nums[p] <= rem) f(p + 1, rem - nums[p]) else 0)
        memo[key] = ans
        return ans
    }
    return f(0, TGT)
}

fun partB(nums: List<Int>): Int {
    val n = nums.size
    val f_memo = mutableMapOf<Pair<Int, Int>, Int>()
    fun f(p: Int, rem: Int): Int {
        if(rem < 0)
            return n + 1
        if(p == n)
            return if(rem == 0) 0 else n + 1
        val key = Pair(p, rem)
        f_memo[key]?.let{
            return it
        }
        val ans = min(f(p + 1, rem), 1 + f(p + 1, rem - nums[p]))
        f_memo[key] = ans
        return ans
    }
    val bst = f(0, TGT)
    val g_memo = mutableMapOf<Triple<Int, Int, Int>, Int>()
    fun g(p: Int, rem: Int, left: Int): Int {
        if(rem < 0)
            return 0
        if(left < 0)
            return 0
        if(p == n)
            return if(rem == 0 && left == 0) 1 else 0
        val key = Triple(p, rem, left)
        g_memo[key]?.let{
            return it
        }
        val ans = g(p + 1, rem, left) + g(p + 1, rem - nums[p], left - 1)
        g_memo[key] = ans
        return ans
    }
    return g(0, TGT, bst)
}

fun main(){
    val nums = generateSequence(::readlnOrNull).map{it.toInt()}.toList()
    println("Part A: ${partA(nums)}")
    println("Part B: ${partB(nums)}")
}
main()
