
object Solution {
    def maxCount(banned: Array[Int], n: Int, maxSum: Int): Int = {
        val bannedSet = banned.toSet
        val numbers = (1 to n).filter(!bannedSet.contains(_))
        numbers.zipWithIndex
               .foldLeft(Left(0).asInstanceOf[Either[Int, Int]]) {
            case (Left(sum), (cur, id)) =>
                if sum + cur > maxSum then Right(id)
                else Left(sum + cur)
            case (right, _) => right
        } match {
            case Left(_) => numbers.length
            case Right(len) => len
        }
    }
}