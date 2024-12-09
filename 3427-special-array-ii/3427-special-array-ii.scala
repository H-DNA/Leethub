object Solution {
    def lastSmallerIndex(nums: Array[Int], value: Int): Int = {
        def lastSmallerIndexIter(left: Int, right: Int): Int = {
            val mid = (left + right) / 2
            if (left > right) {
                left - 1
            } else if (nums(mid) > value) {
                lastSmallerIndexIter(left, mid - 1)
            } else if (nums(mid) == value) {
                mid
            } else {
                lastSmallerIndexIter(mid + 1, right)
            }
        }
        lastSmallerIndexIter(0, nums.length)
    }

    def isArraySpecial(nums: Array[Int], queries: Array[Array[Int]]): Array[Boolean] = {
        var mismatchedIndexes = Array[Int]()
        mismatchedIndexes :+= 0
        for ((value, idx) <- nums.view.zipWithIndex) {
            if (idx > 0 && value % 2 + nums(idx - 1) % 2 != 1) {
                mismatchedIndexes :+= idx
            }
        }
        mismatchedIndexes :+= nums.length
        var res = Array[Boolean]()

        for (query <- queries) {
            val idx = lastSmallerIndex(mismatchedIndexes, query(0))
            res :+= mismatchedIndexes(idx + 1) > query(1)
        }

        res
    }
}