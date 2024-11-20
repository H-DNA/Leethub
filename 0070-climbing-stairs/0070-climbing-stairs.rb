# @param {Integer} n
# @return {Integer}
def climb_stairs(n)
    dp = Array::new(n + 1)
    dp[0] = 1
    dp[1] = 1
    for i in 2..n
        dp[i] = dp[i - 1] + dp[i - 2]
    end

    return dp[n]
end