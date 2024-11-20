# @param {String} s
# @return {Integer}
def score_of_string(s)
    s[1..].bytes
          .zip(s.bytes)
          .map { |(a, b)| (a - b).abs }
          .reduce :+            
end