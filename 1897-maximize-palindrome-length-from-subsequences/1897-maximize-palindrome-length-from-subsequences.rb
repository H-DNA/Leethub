# @param {String} word1
# @param {String} word2
# @return {Integer}
def longest_palindrome_dp(word, dp)
    (0...word.length).each { |i| 
        dp[i][i] = 1
    }
    (1...word.length).each { |k|
        (0...word.length - k).each { |i|
            j = k + i
            if word[i] != word[j]
                dp[i][j] = [dp[i + 1][j], dp[i][j - 1]].max
            else
                dp[i][j] = [dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1] + 2].max 
            end
        }
    }
end

def longest_palindrome_sub(word, bound, dp)
    longest_palindrome_dp(word, dp)
    longest = 0
    (0...bound).each { |i| 
        j = word.rindex word[i]
        if !j or j < bound
            next
        end
        longest = [longest, dp[i][j]].max
    }
    longest
end

def longest_palindrome(word1, word2)
    dp = Array.new (word1.length + word2.length)
    (0...word1.length + word2.length).each { |i|
        dp[i] = Array.new (word1.length + word2.length), 0
    }
    word = word1 + word2
    bound = word1.length
    longest_palindrome_sub(word, bound, dp)
end