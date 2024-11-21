object Solution {
    def isPalindrome(x: Int): Boolean = {
        val str = x.toString()
        str == str.reverse
    }
}